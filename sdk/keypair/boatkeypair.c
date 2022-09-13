/******************************************************************************
 * Copyright (C) 2018-2021 aitos.io
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

/*!@brief Boatkeypair  entry
@author aitos.io
*/
#include "boatconfig.h"
#include "boatinternal.h"
#include "boatkeypair.h"

#include "persiststore.h"
#include "cJSON.h"

#if RPC_USE_LIBCURL == 1
#include "curl/curl.h"
#endif


/**
 * @description: 
 *  This function get one keypair data from Nvram include persistent space and non-persistent space
 * @param {BoatKeypairDataCtx} *keypairdata
 * @param {BUINT32} startAddr
 *  from this addr to read one keypair data
 * @param {BoatStoreType} storeType
 *  read from persistent space or non-persistent space
 * @param {BUINT32*} outlen
 *  length of each keypair data
 * @return {*}
 *  This function returns BOAT_SUCCESS if successfully executed.
 *  Otherwise it returns one of the error codes. Refer to header file boaterrcode.h 
 *  for details.
 * @author: aitos
 */
__BOATSTATIC BOAT_RESULT BoATKeypair_GetKeypairFromNvram(BoatKeypairDataCtx *keypairdata , BUINT32 startAddr,BoatStoreType storeType,BUINT32 *outlen)
{
    BOAT_RESULT result = BOAT_SUCCESS;
    BUINT32 keypairDataLength = 0 , keypairDataLengthLen = 0 , paramDataLength = 0 , paramDataLengthLen = 0;
    BUINT32 offset = 0 , offset_obj= 0;
    BUINT8 lengthbytes[3] = {0};

    offset = startAddr;
    /*read the data length of each keypair */
        result = BoatReadSoftRotNvram(BOAT_STORE_KEYPAIR,offset,lengthbytes,sizeof(lengthbytes),storeType);
        if(result != BOAT_SUCCESS){
            BoatLog(BOAT_LOG_NORMAL,"Read keypair length fail , errorcode = %d ",result);
            return result;
        }
        keypairDataLength = UtilityGetLVData_L(lengthbytes);
        if(keypairDataLength < 0){
            BoatLog(BOAT_LOG_NORMAL,"keypair data length err ");
            return BOAT_ERROR;
        }
        keypairDataLengthLen = UtilityGetTLV_LL_from_len(keypairDataLength);
        offset += keypairDataLengthLen;
        offset_obj = offset;
        /* begin to read keypair index */
        result = BoatReadSoftRotNvram(BOAT_STORE_KEYPAIR,offset,lengthbytes,sizeof(lengthbytes),storeType);
        if(result != BOAT_SUCCESS){
            BoatLog(BOAT_LOG_NORMAL,"Read keypair length fail , errorcode = %d ",result);
            return result;
        }
        paramDataLength = UtilityGetLVData_L(lengthbytes);
        if(paramDataLength < 0){
            BoatLog(BOAT_LOG_NORMAL,"keypair data length err ");
            return BOAT_ERROR;
        }
        if(paramDataLength != 1){
            BoatLog(BOAT_LOG_NORMAL,"keypair index data err ");
            return BOAT_ERROR;
        }
        paramDataLengthLen = UtilityGetTLV_LL_from_len(paramDataLength);
        offset += paramDataLengthLen;
        if(offset - offset_obj + paramDataLength > keypairDataLength ){
            BoatLog(BOAT_LOG_NORMAL,"keypair index data err ");
            return BOAT_ERROR;
        }
        result = BoatReadSoftRotNvram(BOAT_STORE_KEYPAIR,offset,&(keypairdata->prikeyCtx.keypair_index),paramDataLength,storeType);
        if(result != BOAT_SUCCESS){
            BoatLog(BOAT_LOG_NORMAL,"Read keypair index fail , errorcode = %d ",result);
            return result;
        }
        offset += paramDataLength;
        /* begin to read keypair name */
        result = BoatReadSoftRotNvram(BOAT_STORE_KEYPAIR,offset,lengthbytes,sizeof(lengthbytes),storeType);
        if(result != BOAT_SUCCESS){
            BoatLog(BOAT_LOG_NORMAL,"Read keypair length fail , errorcode = %d ",result);
            return result;
        }
        paramDataLength = UtilityGetLVData_L(lengthbytes);
        if(paramDataLength < 0){
            BoatLog(BOAT_LOG_NORMAL,"keypair data length err ");
            return BOAT_ERROR;
        }
        paramDataLengthLen = UtilityGetTLV_LL_from_len(paramDataLength);
        offset += paramDataLengthLen;
        if(offset - offset_obj + paramDataLength > keypairDataLength ){
            BoatLog(BOAT_LOG_NORMAL,"keypair name data err ");
            return BOAT_ERROR;
        }
        keypairdata->prikeyCtx.keypair_name = BoatMalloc(paramDataLength + 1);
        keypairdata->prikeyCtx.keypair_name[paramDataLength] = 0;
        result = BoatReadSoftRotNvram(BOAT_STORE_KEYPAIR,offset,(BUINT8*)keypairdata->prikeyCtx.keypair_name,paramDataLength,storeType);
        if(result != BOAT_SUCCESS){
            BoatLog(BOAT_LOG_NORMAL,"Read keypair index fail , errorcode = %d ",result);
            return result;
        }
        offset += paramDataLength;
        /* read keypair PriKeyFormat */     
        result = BoatReadSoftRotNvram(BOAT_STORE_KEYPAIR,offset,lengthbytes,sizeof(lengthbytes),storeType);
        if(result != BOAT_SUCCESS){
            BoatLog(BOAT_LOG_NORMAL,"Read keypair length fail , errorcode = %d ",result);
            return result;
        }
        paramDataLength = UtilityGetLVData_L(lengthbytes);
        if(paramDataLength < 0){
            BoatLog(BOAT_LOG_NORMAL,"keypair data length err ");
            return BOAT_ERROR;
        }
        // if(paramDataLength != 1){
        //     BoatLog(BOAT_LOG_NORMAL,"keypair format data err ");
        //     return BOAT_ERROR;
        // }
        paramDataLengthLen = UtilityGetTLV_LL_from_len(paramDataLength);
        offset += paramDataLengthLen;
        if(offset - offset_obj + paramDataLength > keypairDataLength ){
            BoatLog(BOAT_LOG_NORMAL,"keypair format len err ");
            return BOAT_ERROR;
        }
        result = BoatReadSoftRotNvram(BOAT_STORE_KEYPAIR,offset,(BUINT8*)&(keypairdata->prikeyCtx.prikey_format),paramDataLength,storeType);
        if(result != BOAT_SUCCESS){
            BoatLog(BOAT_LOG_NORMAL,"Read keypair index fail , errorcode = %d ",result);
            return result;
        }
        offset += paramDataLength;    
        /* read keypair PriKeyType */ 
        result = BoatReadSoftRotNvram(BOAT_STORE_KEYPAIR,offset,lengthbytes,sizeof(lengthbytes),storeType);
        if(result != BOAT_SUCCESS){
            BoatLog(BOAT_LOG_NORMAL,"Read keypair length fail , errorcode = %d ",result);
            return result;
        }
        paramDataLength = UtilityGetLVData_L(lengthbytes);
        if(paramDataLength < 0){
            BoatLog(BOAT_LOG_NORMAL,"keypair data length err ");
            return BOAT_ERROR;
        }
        // if(paramDataLength != 1){
        //     BoatLog(BOAT_LOG_NORMAL,"keypair key type data err ");
        //     return BOAT_ERROR;
        // }
        paramDataLengthLen = UtilityGetTLV_LL_from_len(paramDataLength);
        offset += paramDataLengthLen;
        if(offset - offset_obj + paramDataLength > keypairDataLength ){
            BoatLog(BOAT_LOG_NORMAL,"keypair key type data err ");
            return BOAT_ERROR;
        }
        result = BoatReadSoftRotNvram(BOAT_STORE_KEYPAIR,offset,(BUINT8*)&(keypairdata->prikeyCtx.prikey_type),paramDataLength,storeType);
        if(result != BOAT_SUCCESS){
            BoatLog(BOAT_LOG_NORMAL,"Read keypair index fail , errorcode = %d ",result);
            return result;
        }
        offset += paramDataLength;
        /* read keypair public key */
        result = BoatReadSoftRotNvram(BOAT_STORE_KEYPAIR,offset,lengthbytes,sizeof(lengthbytes),storeType);
        if(result != BOAT_SUCCESS){
            BoatLog(BOAT_LOG_NORMAL,"Read keypair length fail , errorcode = %d ",result);
            return result;
        }
        paramDataLength = UtilityGetLVData_L(lengthbytes);
        if(paramDataLength < 0){
            BoatLog(BOAT_LOG_NORMAL,"keypair data length err ");
            return BOAT_ERROR;
        }
        if(paramDataLength != 64){
            BoatLog(BOAT_LOG_NORMAL,"keypair pubkey data len err , len = %d ",paramDataLength);
            return BOAT_ERROR;
        }
        paramDataLengthLen = UtilityGetTLV_LL_from_len(paramDataLength);
        offset += paramDataLengthLen;
        if(offset - offset_obj + paramDataLength > keypairDataLength ){
            BoatLog(BOAT_LOG_NORMAL,"keypair pubkey data err ");
            return BOAT_ERROR;
        }
        result = BoatReadSoftRotNvram(BOAT_STORE_KEYPAIR,offset,keypairdata->prikeyCtx.pubkey_content,paramDataLength,storeType);
        if(result != BOAT_SUCCESS){
            BoatLog(BOAT_LOG_NORMAL,"Read keypair index fail , errorcode = %d ",result);
            return result;
        }
        *outlen = (keypairDataLength + keypairDataLengthLen);

    return result;
}



/**
 * @description: 
 *  This function read keypair data from Nvram by index. Not read prikey content.
 * @param {BoatKeypairPriKeyCtx} *PriKeyCtx
 * @param {BUINT8} index
 *  the keypair index want to read
 * @return {*}
 *  This function returns BOAT_SUCCESS if successfully executed.
 *  Otherwise it returns one of the error codes. Refer to header file boaterrcode.h 
 *  for details.
 * @author: aitos
 */
BOAT_RESULT BoATKeypair_GetKeypairByIndex(BoatKeypairPriKeyCtx *priKeyCtx ,BUINT8 index)
{
    BOAT_RESULT result = BOAT_SUCCESS;
	BUINT8 keypairNum = 0 , keypairIndex = 0;
	BUINT32 offset = 0 , offset_obj = 0;
	BUINT32  keypairLength = 0 , keypairLengthLen = 0 , paramLength = 0 , paramLengthLen = 0;
	BUINT8 lengthBytes[3] = {0};
    BoatStoreType storetype;

    if(index == 0){  // onetime keypair
        storetype = BOAT_STORE_TYPE_RAM;
    }else{
        storetype = BOAT_STORE_TYPE_FLASH;
    }

	result = BoatReadSoftRotNvram(BOAT_STORE_KEYPAIR,offset,&keypairNum,1,storetype);
    /* if read Nvram failed , no keypair */
    if(result != BOAT_SUCCESS || keypairNum == 0){
        BoatLog(BOAT_LOG_NORMAL,"read keypair num ret = %d  num = %d ",result,keypairNum);
        return BOAT_ERROR;
    }
	offset ++ ;
	for (BUINT8 i = 0; i < keypairNum; i++)
	{
		/* keypair length */
		result = BoatReadSoftRotNvram(BOAT_STORE_KEYPAIR,offset,lengthBytes,sizeof(lengthBytes),storetype);
		if(result != BOAT_SUCCESS){
			BoatLog(BOAT_LOG_NORMAL,"get keypair[%d] length fail " , i);
			return result;
		}
		keypairLength = UtilityGetLVData_L(lengthBytes);
        if(keypairLength < 0){
            BoatLog(BOAT_LOG_NORMAL,"keypair data length err ");
            return BOAT_ERROR;
        }
        keypairLengthLen = UtilityGetTLV_LL_from_len(keypairLength);
		offset += keypairLengthLen;
		offset_obj = offset;
		/* keypair index */
		result = BoatReadSoftRotNvram(BOAT_STORE_KEYPAIR,offset,lengthBytes,sizeof(lengthBytes),storetype);
		if(result != BOAT_SUCCESS){
			BoatLog(BOAT_LOG_NORMAL,"get keypair[%d] index fail " , i);
			return result;
		}
		paramLength = UtilityGetLVData_L(lengthBytes);
		if(paramLength != 1){
            BoatLog(BOAT_LOG_NORMAL,"keypair index length err ");
            return BOAT_ERROR;
        }
		keypairIndex = lengthBytes[1];
		if(keypairIndex == index){
            priKeyCtx->keypair_index = index;
			offset += 2;
			if(offset - offset_obj > keypairLength){  // offset over the length of this walet
                BoatLog(BOAT_LOG_NORMAL,"keypair name offset over keypair length");
				return BOAT_ERROR;
			}
			/* keypair name */
			result = BoatReadSoftRotNvram(BOAT_STORE_KEYPAIR,offset,lengthBytes,sizeof(lengthBytes),storetype);
			if(result != BOAT_SUCCESS){
				BoatLog(BOAT_LOG_NORMAL,"get keypair[%d] index fail " , i);
				return result;
			}
			paramLength = UtilityGetLVData_L(lengthBytes);
			if(paramLength < 0){
            	BoatLog(BOAT_LOG_NORMAL,"keypair name length err ");
            	return BOAT_ERROR;
        	}
			paramLengthLen = UtilityGetTLV_LL_from_len(paramLength);
            offset += paramLengthLen;
            if(offset - offset_obj + paramLength > keypairLength){  // offset over the length of this walet
				BoatLog(BOAT_LOG_NORMAL,"keypair name data offset over keypair length");
                return BOAT_ERROR;
			}
            priKeyCtx->keypair_name = BoatMalloc(paramLength);
            if(priKeyCtx->keypair_name == NULL){
                return BOAT_ERROR;
            }
            result = BoatReadSoftRotNvram(BOAT_STORE_KEYPAIR,offset,(BUINT8*)priKeyCtx->keypair_name,paramLength,storetype);
			if(result != BOAT_SUCCESS){
				BoatLog(BOAT_LOG_NORMAL,"get keypair[%d] name  fail " , i);
				return result;
			}
			offset += paramLength ;
			/* keypair PriKeyFormat */
			result = BoatReadSoftRotNvram(BOAT_STORE_KEYPAIR,offset,lengthBytes,sizeof(lengthBytes),storetype);
			if(result != BOAT_SUCCESS){
				BoatLog(BOAT_LOG_NORMAL,"get keypair[%d] prikey format fail " , i);
				return result;
			}
			paramLength = UtilityGetLVData_L(lengthBytes);
			if(paramLength < 0){
            	BoatLog(BOAT_LOG_NORMAL,"keypair prike format length err ");
            	return BOAT_ERROR;
        	}
			paramLengthLen = UtilityGetTLV_LL_from_len(paramLength);
            offset += paramLengthLen;
            if(offset - offset_obj + paramLength > keypairLength){  // offset over the length of this walet
				BoatLog(BOAT_LOG_NORMAL,"keypair format offset over keypair length");
                return BOAT_ERROR;
			}
            result = BoatReadSoftRotNvram(BOAT_STORE_KEYPAIR,offset,(BUINT8 *)&(priKeyCtx->prikey_format),paramLength,storetype);
			if(result != BOAT_SUCCESS){
				BoatLog(BOAT_LOG_NORMAL,"get keypair[%d] prikey format  fail " , i);
				return result;
			}
			offset += paramLength ;
			/* keypair prikey type */
			result = BoatReadSoftRotNvram(BOAT_STORE_KEYPAIR,offset,lengthBytes,sizeof(lengthBytes),storetype);
			if(result != BOAT_SUCCESS){
				BoatLog(BOAT_LOG_NORMAL,"get keypair[%d] prikey type fail " , i);
				return result;
			}
			paramLength = UtilityGetLVData_L(lengthBytes);
			if(paramLength < 0){
            	BoatLog(BOAT_LOG_NORMAL,"keypair prike type length err ");
            	return BOAT_ERROR;
        	}
			paramLengthLen = UtilityGetTLV_LL_from_len(paramLength);
            offset += paramLengthLen;
            if(offset - offset_obj + paramLength > keypairLength){  // offset over the length of this walet
				BoatLog(BOAT_LOG_NORMAL,"keypair type offset over keypair length");
                return BOAT_ERROR;
			}
            result = BoatReadSoftRotNvram(BOAT_STORE_KEYPAIR,offset,(BUINT8 *)&(priKeyCtx->prikey_type),paramLength,storetype);
			if(result != BOAT_SUCCESS){
				BoatLog(BOAT_LOG_NORMAL,"get keypair[%d] prikey type  fail " , i);
				return result;
			}
			offset += paramLength ;
			/* keypair pubkey */
			result = BoatReadSoftRotNvram(BOAT_STORE_KEYPAIR,offset,lengthBytes,sizeof(lengthBytes),storetype);
			if(result != BOAT_SUCCESS){
				BoatLog(BOAT_LOG_NORMAL,"get keypair[%d] pubkey fail " , i);
				return result;
			}
			paramLength = UtilityGetLVData_L(lengthBytes);
			if(paramLength < 0){
            	BoatLog(BOAT_LOG_NORMAL,"keypair pubkey length err ");
            	return BOAT_ERROR;
        	}
			paramLengthLen = UtilityGetTLV_LL_from_len(paramLength);
            offset += paramLengthLen;
            if(offset - offset_obj + paramLength > keypairLength){  // offset over the length of this walet
				BoatLog(BOAT_LOG_NORMAL,"keypair pubkey offset over keypair length");
                return BOAT_ERROR;
			}
            result = BoatReadSoftRotNvram(BOAT_STORE_KEYPAIR,offset,(priKeyCtx->pubkey_content),paramLength,storetype);
			if(result != BOAT_SUCCESS){
				BoatLog(BOAT_LOG_NORMAL,"get keypair[%d] pubkey  fail " , i);
				return result;
			}
			offset += paramLength ;
			return result;
		}else{ // the next keypair
			offset += keypairLength;
		}
	}
    return BOAT_ERROR;
}

/**
 * @description: 
 *  This function get keypair list ,include persistent keypairs and onetime keypair
 * @param[out] {BoatIotKeypairContext} *keypairList
 * @return {*}
 *  This function returns BOAT_SUCCESS if successfully executed.
 *  Otherwise it returns one of the error codes. Refer to header file boaterrcode.h 
 *  for details.
 * @author: aitos
 */
BOAT_RESULT BoATKeypair_GetKeypairList(BoatIotKeypairContext *keypairList)
{
    BOAT_RESULT result = BOAT_SUCCESS;
    BUINT8 keypairNum = 0;
    BUINT8 index = 0;
    BUINT32 keypairDataLength = 0 ;
    BUINT32 offset = 0 ;
    // BUINT8 lengthbytes[3] = {0};
    /* persistent keypair  */
    result = BoatReadSoftRotNvram(BOAT_STORE_KEYPAIR,offset,&keypairNum,1,BOAT_STORE_TYPE_FLASH);
    BoatLog(BOAT_LOG_NORMAL,"read flash keypair num = %d ,result = %d",keypairNum,result);
    /* if read Nvram failed , no keypair */
    if(result != BOAT_SUCCESS){
        keypairNum = 0;
        // return BOAT_SUCCESS;
    }
    (*keypairList).keypairNum = keypairNum;
    offset += 1;
    for (int i = 0; i < keypairNum; i++)
    {
        /* code */
        result = BoATKeypair_GetKeypairFromNvram(&(keypairList->keypairs[index++]),offset,BOAT_STORE_TYPE_FLASH,&keypairDataLength);
        if(result != BOAT_SUCCESS){
            return result;
        }
        offset += keypairDataLength;

    }
    /* onetime keypair  */
    offset = 0;
    result = BoatReadSoftRotNvram(BOAT_STORE_KEYPAIR,offset,&keypairNum,1,BOAT_STORE_TYPE_RAM);
    if(result != BOAT_SUCCESS){
        keypairNum = 0;
        // return BOAT_SUCCESS;
    }
    BoatLog(BOAT_LOG_NORMAL,"read ram keypair num = %d ,result = %d",keypairNum,result);
    (*keypairList).keypairNum += keypairNum;
    offset += 1;
    for (int i = 0; i < keypairNum; i++)
    {
        /* code */
        result = BoATKeypair_GetKeypairFromNvram(&(keypairList->keypairs[index++]),offset,BOAT_STORE_TYPE_RAM,&keypairDataLength);
        if(result != BOAT_SUCCESS){
            return result;
        }
        offset += keypairDataLength;

    }

    return result;
}

/**
 * @description: 
 *  This function use to free BoatIotKeypairContext param.
 * @param[in] {BoatIotKeypairContext} keypairList
 * @return {*}
 *  This function returns BOAT_SUCCESS if successfully executed.
 *  Otherwise it returns one of the error codes. Refer to header file boaterrcode.h 
 *  for details.
 * @author: aitos
 */
BOAT_RESULT BoATKeypair_FreeKeypairContext(BoatIotKeypairContext keypairList)
{
    if(keypairList.keypairNum == 0){
        return BOAT_SUCCESS;
    }
    for (int i = 0; i < keypairList.keypairNum; i++)
    {
        /* code */
        keypairList.keypairs[i].prikeyCtx.prikey_format = BOAT_KEYPAIR_PRIKEY_FORMAT_UNKNOWN;
        keypairList.keypairs[i].prikeyCtx.prikey_type = BOAT_KEYPAIR_PRIKEY_TYPE_UNKNOWN;
        memset(keypairList.keypairs[i].prikeyCtx.pubkey_content,0x00,sizeof(keypairList.keypairs[i].prikeyCtx.pubkey_content));
        keypairList.keypairs[i].prikeyCtx.keypair_index = 0;
        if(keypairList.keypairs[i].prikeyCtx.keypair_name != NULL){
            BoatFree(keypairList.keypairs[i].prikeyCtx.keypair_name);
        }
    }
    keypairList.keypairNum = 0;
    return BOAT_SUCCESS;
    
}

/**
 * @description: 
 *  This function initialize keypair list
 * @param[inout] {BoatKeypairDataCtx} *mKeypairDataCtx
 * @return 
 *   This function returns BOAT_SUCCESS if initialization is successful.\n
 *   Otherwise it returns one of the error codes. Refer to header file boaterrcode.h 
 *   for details.
 * @author: aitos
 */
__BOATSTATIC BOAT_RESULT BoATKeypair_Init_BoatIotKeypairContext(BoatIotKeypairContext *mKeypairList){
    mKeypairList->keypairNum = 0;
    for (int i = 0; i < BOAT_MAX_KEYPAIR_NUM; i++)
    {
        /* code */
        mKeypairList->keypairs[i].extraData.value_len = 0;
        memset(mKeypairList->keypairs[i].extraData.value,0x00,sizeof(mKeypairList->keypairs[i].extraData.value));
        mKeypairList->keypairs[i].prikeyCtx.keypair_index = 0;
        mKeypairList->keypairs[i].prikeyCtx.keypair_name = NULL;
    }
    
    return BOAT_SUCCESS;
}



/**
 * @description: 
 *  This function get unused keypair index from persistent keypairs.
 * @return {*}
 *  This function returns unused keypair index if successfully executed.
 *  Otherwise it returns one of the error codes. Refer to header file boaterrcode.h 
 *  for details.
 * @author: aitos
 */
__BOATSTATIC BOAT_RESULT BoATKeypair_GetFreeIndex_From_Persistent(void)
{
    BOAT_RESULT result = BOAT_ERROR;
    // BUINT8 flag = 0;
    int i ,j;
    BoatIotKeypairContext keypairList;
    BoATKeypair_Init_BoatIotKeypairContext(&keypairList);
    result = BoATKeypair_GetKeypairList(&keypairList);
    if(result != BOAT_SUCCESS){
        // BoATKeypair_FreeKeypairContext(keypairList);
        // return result;
        BoatLog(BOAT_LOG_NORMAL,"get keypair list fail");
    }
    if(keypairList.keypairNum == BOAT_MAX_KEYPAIR_NUM){
        BoATKeypair_FreeKeypairContext(keypairList);
        return BOAT_ERROR;
    }
    for (i = 0; i < BOAT_MAX_KEYPAIR_NUM; i++)
    {
        /* code */
        for ( j = 0; j < keypairList.keypairNum; j++)
        {
            /* code */
            if(keypairList.keypairs[j].prikeyCtx.keypair_index == (i+1))
            {
                // BoATKeypair_FreeKeypairContext(keypairList);
                // return i;
                break;
            }
        }
        if(j == keypairList.keypairNum){
            BoATKeypair_FreeKeypairContext(keypairList);
            return i+1;
        }
    }
    BoATKeypair_FreeKeypairContext(keypairList);
    if(keypairList.keypairNum == 0){
        BoatLog(BOAT_LOG_NORMAL,"have no keypair");
        return 0;
    }
    return BOAT_ERROR;
}

/**
 * @description: 
 *  This function get the length of keypair data. 
 *  data like this:
 *  L  LV LV LV 
 * @param[in] {BoatKeypairDataCtx} *mKeypairDataCtx
 * @param[out] {BUINT32} *len
 *  length of all the keypair data
 * @return {*}
 *  This function returns BoAT_SUCCESS if successfully executed.
 *  Otherwise it returns one of the error codes. Refer to header file boaterrcode.h 
 *  for details.
 * @author: aitos
 */
__BOATSTATIC BOAT_RESULT BoATKeypair_Get_DataCtx_Len(BoatKeypairDataCtx *mKeypairDataCtx,BUINT32 *len)
{
    BUINT32 paramLength = 0,paramLengthLen = 0;
    BUINT32 keypairLength = 0;
    if(mKeypairDataCtx == NULL){
        BoatLog(BOAT_LOG_NORMAL,"mKeypairDataCtx is NULL");
        return BOAT_ERROR;
    }
    if(mKeypairDataCtx->prikeyCtx.keypair_name == NULL){
        BoatLog(BOAT_LOG_NORMAL,"keypair name  is NULL");
        return BOAT_ERROR;
    }
    /* keypair index*/
    paramLength = sizeof(mKeypairDataCtx->prikeyCtx.keypair_index);
    paramLengthLen =   UtilityGetTLV_LL_from_len(paramLength);
    keypairLength += (paramLength + paramLengthLen);
    /*keypair name*/
    paramLength = strlen(mKeypairDataCtx->prikeyCtx.keypair_name);
    paramLengthLen  = UtilityGetTLV_LL_from_len(paramLength);
    keypairLength += (paramLength + paramLengthLen);
    /* keypair PriKeyFormat */
    paramLength = sizeof(mKeypairDataCtx->prikeyCtx.prikey_format);
    paramLengthLen  = UtilityGetTLV_LL_from_len(paramLength);
    keypairLength += (paramLength + paramLengthLen);
    /* keypair prikey type*/
    paramLength = sizeof(mKeypairDataCtx->prikeyCtx.prikey_type);
    paramLengthLen  = UtilityGetTLV_LL_from_len(paramLength);
    keypairLength += (paramLength + paramLengthLen);
    /* keypair pubkey */
    paramLength = sizeof(mKeypairDataCtx->prikeyCtx.pubkey_content);
    paramLengthLen  = UtilityGetTLV_LL_from_len(paramLength);
    keypairLength += (paramLength + paramLengthLen);
    /* keypair prikey */
    //*data_len + 31 + 32 + 16 + 16
    paramLength = mKeypairDataCtx->extraData.value_len + 31 + 32 + 16 + 16;
    paramLengthLen  = UtilityGetTLV_LL_from_len(paramLength);
    keypairLength += (paramLength + paramLengthLen);
    /* all the data*/
    paramLengthLen  = UtilityGetTLV_LL_from_len(keypairLength);
    keypairLength +=  paramLengthLen;
    BoatLog(BOAT_LOG_NORMAL,"keypairLength = %d ",keypairLength);
    *len = keypairLength;
    return BOAT_SUCCESS;
}

/**
 * @description: 
 *  This function get all the data of keypair.
 *  like this:
 *  L  LV LV LV 
 * @param {BoatKeypairDataCtx} *mKeypairDataCtx
 * @param {BUINT8} *data
 * keypair data
 * @param[in/out] {BUINT32} *datalen
 * in: length of data
 * out: real length of keypair data
 * @return {*}
 *  This function returns BoAT_SUCCESS if successfully executed.
 *  Otherwise it returns one of the error codes. Refer to header file boaterrcode.h 
 *  for details.
 * @author: aitos
 */
__BOATSTATIC BOAT_RESULT BoATKeypair_Get_DataCtx_Data(BoatKeypairDataCtx *mKeypairDataCtx,BUINT8 *data,BUINT32 *datalen)
{
    BOAT_RESULT result = BOAT_SUCCESS;
    BUINT32 paramLength = 0;
    BUINT32 keypairLength = 0,offset = 0;
    if(mKeypairDataCtx == NULL){
        BoatLog(BOAT_LOG_NORMAL,"keypair data is NULL");
        return BOAT_ERROR;
    }
    if(data == NULL ){
        BoatLog(BOAT_LOG_NORMAL,"out data  buf is NULL");
        return BOAT_ERROR;
    }

    /* keypair index*/
   data[offset] = mKeypairDataCtx->prikeyCtx.keypair_index;
   result = add_L_withOffset(data,&offset,sizeof(mKeypairDataCtx->prikeyCtx.keypair_index));
   if(result < BOAT_SUCCESS){
    BoatLog(BOAT_LOG_NORMAL,"get keypair index LV fail");
    return BOAT_ERROR;
   }
    /*keypair name*/
    memcpy(data+offset,mKeypairDataCtx->prikeyCtx.keypair_name,strlen(mKeypairDataCtx->prikeyCtx.keypair_name));
    result = add_L_withOffset(data,&offset,strlen(mKeypairDataCtx->prikeyCtx.keypair_name));
    if(result < BOAT_SUCCESS){
        BoatLog(BOAT_LOG_NORMAL,"get keypair name LV fail");
        return BOAT_ERROR;
    }
    /* keypair PriKeyFormat */
    // data[offset] = mKeypairDataCtx->prikeyCtx.prikey_format;
    memcpy(data+offset,&(mKeypairDataCtx->prikeyCtx.prikey_format),sizeof(mKeypairDataCtx->prikeyCtx.prikey_format));
    result = add_L_withOffset(data,&offset,sizeof(mKeypairDataCtx->prikeyCtx.prikey_format));
    if(result < BOAT_SUCCESS){
        BoatLog(BOAT_LOG_NORMAL,"get keypair format LV fail");
    return BOAT_ERROR;
    }
    /* keypair prikey type*/
    // data[offset] = mKeypairDataCtx->prikeyCtx.prikey_type;
    memcpy(data+offset,&(mKeypairDataCtx->prikeyCtx.prikey_type),sizeof(mKeypairDataCtx->prikeyCtx.prikey_type));
    result = add_L_withOffset(data,&offset,sizeof(mKeypairDataCtx->prikeyCtx.prikey_type));
    if(result < BOAT_SUCCESS){
        BoatLog(BOAT_LOG_NORMAL,"get keypair type LV fail");
    return BOAT_ERROR;
    }
    /* keypair pubkey */
    memcpy(data + offset , mKeypairDataCtx->prikeyCtx.pubkey_content,sizeof(mKeypairDataCtx->prikeyCtx.pubkey_content));
    result = add_L_withOffset(data,&offset,sizeof(mKeypairDataCtx->prikeyCtx.pubkey_content));
    if(result < BOAT_SUCCESS){
        BoatLog(BOAT_LOG_NORMAL,"get keypair pubkey LV fail");
    return BOAT_ERROR;
    }
    /* keypair prikey */
    BUINT8 dataEnc[mKeypairDataCtx->extraData.value_len + 31 + 32 + 16 + 16];
    BoatLog_hexdump(BOAT_LOG_NORMAL,"prikey : ",mKeypairDataCtx->extraData.value,mKeypairDataCtx->extraData.value_len);
    result = BoATSoftRotNvramEnc(mKeypairDataCtx->extraData.value,mKeypairDataCtx->extraData.value_len,dataEnc,&paramLength);
    BoatLog_hexdump(BOAT_LOG_NORMAL,"prikey cip : ",dataEnc,paramLength);
    memcpy(data + offset , dataEnc,paramLength);
    result = add_L_withOffset(data,&offset,paramLength);
    if(result < BOAT_SUCCESS){
    BoatLog(BOAT_LOG_NORMAL,"get keypair prikey LV fail");
    return BOAT_ERROR;
    }
    /* all the data*/
    keypairLength = offset;
    offset = 0;
    result = add_L_withOffset(data,&offset,keypairLength);
    if(result < BOAT_SUCCESS){
    return BOAT_ERROR;
    }
    *datalen = offset;
    return BOAT_SUCCESS;
}


/**
 * @description: 
 *   This function store keypair data into Nvram
 * @param {BoatKeypairDataCtx} *mKeypairDataCtx
 * @param {BoatStoreType} storeType
 *  store in persistent or non-persistent space
 * @return {*}
 *  This function returns BOAT_SUCCESS if successfully executed.
 *  Otherwise it returns one of the error codes. Refer to header file boaterrcode.h 
 *  for details.
 * @author: aitos
 */
__BOATSTATIC BOAT_RESULT BoATKeypair_DataCtx_Store(BoatKeypairDataCtx *mKeypairDataCtx,BoatStoreType storeType)
{
    BOAT_RESULT result = BOAT_SUCCESS;
    BUINT8 keypairNum = 0;
    BUINT32 keypairLength = 0 ,keypairLengthLen = 0, offset = 0 ;
    BUINT8 lengthbytes[3] = {0};
    // BUINT8 testbuf[1024] = {0};
    BUINT8 *keypairData = NULL;

    result = BoatReadSoftRotNvram(BOAT_STORE_KEYPAIR,offset,&keypairNum,1,storeType);
    /* if read Nvram failed , no keypair */
    if(result != BOAT_SUCCESS){
        keypairNum = 0;
    }
    if(keypairNum >= BOAT_MAX_KEYPAIR_NUM){
        return BOAT_ERROR;
    }
    if(storeType == BOAT_STORE_TYPE_RAM)
    {
        keypairNum = 0;
    }
    offset += 1;
    for (int i = 0; i < keypairNum; i++)
    {
        /* keypair length */
        result = BoatReadSoftRotNvram(BOAT_STORE_KEYPAIR,offset,lengthbytes,sizeof(lengthbytes),storeType);
        if(result != BOAT_SUCCESS){
            BoatLog(BOAT_LOG_NONE,"read keypair length fail");
            return result;
        }
        keypairLength = UtilityGetLVData_L(lengthbytes);
        if(keypairLength < 0){
            BoatLog(BOAT_LOG_NORMAL,"keypair data length err ");
            return BOAT_ERROR;
        }
        keypairLengthLen = UtilityGetTLV_LL_from_len(keypairLength);
        offset += (keypairLength + keypairLengthLen);
    }
    /* get keypair data */
    result = BoATKeypair_Get_DataCtx_Len(mKeypairDataCtx,&keypairLength);
    if(result < BOAT_SUCCESS){
        return result;
    }
    BoatLog(BOAT_LOG_NONE," keypairLength = %d ",keypairLength);
    keypairData = BoatMalloc(keypairLength);
    if(keypairData == NULL){
        return BOAT_ERROR;
    }
    result = BoATKeypair_Get_DataCtx_Data(mKeypairDataCtx,keypairData,&keypairLength);
    if(result != BOAT_SUCCESS){
        BoatLog(BOAT_LOG_NONE," get keypair data fail ");
        BoatFree(keypairData);
        return result;
    }
    BoatLog_hexdump(BOAT_LOG_NORMAL," keypair data : ",keypairData,keypairLength);
    /* store keypair data */
    result = BoATStoreSoftRotNvram(BOAT_STORE_KEYPAIR,offset,keypairData,keypairLength,storeType);
    if(result != BOAT_SUCCESS){
        return result;
    }
    // result = BoatReadSoftRotNvram(0,testbuf,4,0);
    // BoatLog_hexdump(BOAT_LOG_NORMAL,"store data 000 : ",testbuf,4);
    BoatFree(keypairData);
    keypairNum ++;
    result = BoATStoreSoftRotNvram(BOAT_STORE_KEYPAIR,0,&keypairNum,1,storeType);
    // if(result != BOAT_SUCCESS){
    //     return result;
    // }
    //  result = BoatReadSoftRotNvram(0,testbuf,keypairLength+1,0);
    BoatLog(BOAT_LOG_NONE," keypair num = %d ,result = %d ",keypairNum,result);
    // BoatLog_hexdump(BOAT_LOG_NORMAL,"store data : ",testbuf,keypairLength+1);


    return result;
}




/**
 * @description: 
 *  This function initialize keypair data context
 * @param[inout] {BoatKeypairDataCtx} *mKeypairDataCtx
 * @return 
 *   This function returns BOAT_SUCCESS if initialization is successful.\n
 *   Otherwise it returns one of the error codes. Refer to header file boaterrcode.h 
 *   for details.
 * @author: aitos
 */
BOAT_RESULT BoATIotKeypairInit(BoatKeypairDataCtx *mKeypairDataCtx){
    mKeypairDataCtx->extraData.value_len = 0;
    memset(mKeypairDataCtx->extraData.value,0x00,sizeof(mKeypairDataCtx->extraData.value));
    mKeypairDataCtx->prikeyCtx.prikey_format = BOAT_KEYPAIR_PRIKEY_FORMAT_UNKNOWN;
    mKeypairDataCtx->prikeyCtx.keypair_index = 0;
    mKeypairDataCtx->prikeyCtx.keypair_name = NULL;
    mKeypairDataCtx->prikeyCtx.prikey_type = BOAT_KEYPAIR_PRIKEY_TYPE_UNKNOWN;
    memset(mKeypairDataCtx->prikeyCtx.pubkey_content,0x00,sizeof(mKeypairDataCtx->prikeyCtx.pubkey_content));
    return BOAT_SUCCESS;
}

/**
 * @description: 
 *  This function deinitialize keypair data context
 * @param[inout] {BoatKeypairDataCtx} *mKeypairDataCtx
 * @return 
 *   This function returns BOAT_SUCCESS if initialization is successful.\n
 *   Otherwise it returns one of the error codes. Refer to header file boaterrcode.h 
 *   for details.
 * @author: aitos
 */
BOAT_RESULT BoATIotKeypairDeInit(BoatKeypairDataCtx *mKeypairDataCtx){
    mKeypairDataCtx->extraData.value_len = 0;
    memset(mKeypairDataCtx->extraData.value,0x00,sizeof(mKeypairDataCtx->extraData.value));
    mKeypairDataCtx->prikeyCtx.prikey_format = BOAT_KEYPAIR_PRIKEY_FORMAT_UNKNOWN;
    mKeypairDataCtx->prikeyCtx.keypair_index = 0;
    if(mKeypairDataCtx->prikeyCtx.keypair_name != NULL){
        BoatFree(mKeypairDataCtx->prikeyCtx.keypair_name);
    }
    mKeypairDataCtx->prikeyCtx.keypair_name = NULL;
    mKeypairDataCtx->prikeyCtx.prikey_type = BOAT_KEYPAIR_PRIKEY_TYPE_UNKNOWN;
    memset(mKeypairDataCtx->prikeyCtx.pubkey_content,0x00,sizeof(mKeypairDataCtx->prikeyCtx.pubkey_content));
    return BOAT_SUCCESS;
}
/**
 * @description: 
 * This function creat keypair
 * @param[in] {BoatKeypairPriKeyCtx_config} keypairConfig
 * @param[in] {BCHAR} *keypairName
 *  If keypairName is NULL , BoAT will slect one testing name.
 * @param[in] {BoatStoreType} storeType
 *  For onetime keypair or test , select store in ram .
 *  For persistent keypair ,slect store in flash.
 * @return 
 *   This function returns keypair index if creat keypair successfully.\n
 *   Otherwise it returns one of the error codes. Refer to header file boaterrcode.h 
 *   for details.
 * @author: aitos
 */
BOAT_RESULT BoatKeypairCreate(BoatKeypairPriKeyCtx_config *keypairConfig,BCHAR *keypairName,BoatStoreType storeType)
{
    BOAT_RESULT result = BOAT_SUCCESS;
    BoatKeypairDataCtx mKeypairDataCtx ;
    BUINT8 keypairIndex = 0;
    result = BoATIotKeypairInit(&mKeypairDataCtx);
    if(result != BOAT_SUCCESS){
        return result;
    }
    if(storeType == BOAT_STORE_TYPE_FLASH){
        result = BoATKeypair_GetFreeIndex_From_Persistent();
        if(result < BOAT_SUCCESS){
            return result;
        }
        keypairIndex = result;  // from 1 to BOAT_MAX_KEYPAIR_NUM
    }else{
        keypairIndex = 0;  // the index of onetimekeypair is always 0
    }

    BoatLog(BOAT_LOG_NORMAL,"keypair index = %d ",keypairIndex);
    result = BoatPort_keyCreate(keypairConfig,&mKeypairDataCtx);
    if(result != BOAT_SUCCESS){
        return result;
    }
    BoatLog(BOAT_LOG_NORMAL,"BoatPort_keyCreate success ");
    if(keypairName == NULL){
        mKeypairDataCtx.prikeyCtx.keypair_name = BoatMalloc(strlen("keypair")+2);// keypair+index+/0
        memcpy(mKeypairDataCtx.prikeyCtx.keypair_name,"keypair",strlen("keypair"));
        mKeypairDataCtx.prikeyCtx.keypair_name[strlen("keypair")] = 0x30 + keypairIndex;
        mKeypairDataCtx.prikeyCtx.keypair_name[strlen("keypair")+1] = 0;
    }else{
        mKeypairDataCtx.prikeyCtx.keypair_name = BoatMalloc(strlen(keypairName)+1);
        strcpy(mKeypairDataCtx.prikeyCtx.keypair_name,keypairName);
    }
    mKeypairDataCtx.prikeyCtx.keypair_index = keypairIndex;
    result = BoATKeypair_DataCtx_Store(&mKeypairDataCtx,storeType);
    if(result != BOAT_SUCCESS){
        return result;
    }
    memset(mKeypairDataCtx.extraData.value,0x00,mKeypairDataCtx.extraData.value_len);

    BoATIotKeypairDeInit(&mKeypairDataCtx);
    return keypairIndex;

}

/**
 * @description: 
 *  This function deletes the keypair which keypairIndex equals index.
 *  This function will delete the keypair data in Nvram.
 * @param {BUINT8} index
 *  the index want to delete
 * @return {*}
 *   This function returns BOAT_SUCCESS if delete successfully.\n
 *   Otherwise it returns one of the error codes. Refer to header file boaterrcode.h 
 *   for details.
 * @author: aitos
 */
BOAT_RESULT BoATIotKeypairDelete(BUINT8 index)
{
    BOAT_RESULT result = BOAT_SUCCESS;
    BUINT8 i = 0;
    BUINT8 keypairNum = 0 ,keypairNumNew = 0, keypairIndex = 0;
    BUINT32 offset = 0, offset_moveFrom = 0 , offset_moveTo = 0;
    BUINT32 keypairLength = 0 , keypairLengthLen = 0 , paramLength = 0 , paramLengthLen = 0 ;
    BUINT8 lengthBytes[3] = {0};
    BUINT8 *keypairData = NULL;
    if(index >= BOAT_MAX_KEYPAIR_NUM){
        return BOAT_ERROR;
    }
    /* onetime keypair 
       index of onetime keypair must be 0
    */
    if(index == 0){
        /* set keypair num of onetime keypair to 0 */
        memset(lengthBytes,0x00,sizeof(lengthBytes));
        result = BoATStoreSoftRotNvram(BOAT_STORE_KEYPAIR,0,lengthBytes,sizeof(lengthBytes),BOAT_STORE_TYPE_RAM);
        return result;
    }else{ // persistent keypair
        result = BoatReadSoftRotNvram(BOAT_STORE_KEYPAIR,offset,&keypairNum,1,BOAT_STORE_TYPE_FLASH);
    /* if read Nvram failed , no keypair */
    if(result != BOAT_SUCCESS || keypairNum == 0){
        return result;
    }
    offset ++;
    for ( i = 0; i < keypairNum; i++)
    {
        /* read each keypair length */
        result = BoatReadSoftRotNvram(BOAT_STORE_KEYPAIR,offset,lengthBytes,sizeof(lengthBytes),BOAT_STORE_TYPE_FLASH);
        if(result != BOAT_SUCCESS ){
            return result;
        }
        keypairLength = UtilityGetLVData_L(lengthBytes);
        if(keypairLength < 0){
            BoatLog(BOAT_LOG_NORMAL,"keypair data length err ");
            return BOAT_ERROR;
        }
        keypairLengthLen = UtilityGetTLV_LL_from_len(keypairLength);
        // offset += keypairLengthLen;
        /* keypair index  */
        result = BoatReadSoftRotNvram(BOAT_STORE_KEYPAIR,offset + keypairLengthLen,lengthBytes,sizeof(lengthBytes),BOAT_STORE_TYPE_FLASH);
        if(result != BOAT_SUCCESS ){
            return result;
        }
        paramLength = UtilityGetLVData_L(lengthBytes);
        if(paramLength != 1){
            BoatLog(BOAT_LOG_NORMAL,"keypair index length err ");
            return BOAT_ERROR;
        }
        result = BoatReadSoftRotNvram(BOAT_STORE_KEYPAIR,offset + keypairLengthLen + 1,&keypairIndex,sizeof(keypairIndex),BOAT_STORE_TYPE_FLASH);
        if(result != BOAT_SUCCESS ){
            BoatLog(BOAT_LOG_NORMAL,"read keypair index err ");
            return result;
        }
        if(keypairIndex == index){
            break;
        }
        offset += (keypairLengthLen + keypairLength);
    }
    BoatLog(BOAT_LOG_NORMAL,"i= %d ",i);
    if(i >= keypairNum){
        BoatLog(BOAT_LOG_NORMAL,"not find the keypair ");
        return BOAT_ERROR;
    }
    keypairNumNew = keypairNum -1;
    result = BoATStoreSoftRotNvram(BOAT_STORE_KEYPAIR,0,&keypairNumNew,sizeof(keypairNumNew),BOAT_STORE_TYPE_FLASH); // only need to reset keypair length bytes
    if(result != BOAT_SUCCESS){
        BoatLog(BOAT_LOG_NORMAL,"delete keypair fail ");
        return result;
    }

    if(i == (keypairNum -1)){  /* last one keypair*/
        memset(lengthBytes,0x00,sizeof(lengthBytes));
        result = BoATStoreSoftRotNvram(BOAT_STORE_KEYPAIR,offset,lengthBytes,sizeof(lengthBytes),BOAT_STORE_TYPE_FLASH); // only need to reset keypair length bytes
        if(result != BOAT_SUCCESS){
            /* recover keypairNum */
        result = BoATStoreSoftRotNvram(BOAT_STORE_KEYPAIR,offset,&keypairNum,sizeof(keypairNum),BOAT_STORE_TYPE_FLASH); 
        if(result != BOAT_SUCCESS){
            BoatLog(BOAT_LOG_NORMAL,"delete keypair fail ");
            return result;
        }
            BoatLog(BOAT_LOG_NORMAL,"delete keypair fail ");
            return result;
        }
    }else{
        offset_moveTo = offset;
        // the next keypair
        offset += (keypairLengthLen + keypairLength);
        offset_moveFrom = offset;
        i++;  
        keypairLength = 0;
        for ( ; i < keypairNum; i++)
        {
            /* code */
            result = BoatReadSoftRotNvram(BOAT_STORE_KEYPAIR,offset,lengthBytes,sizeof(lengthBytes),BOAT_STORE_TYPE_FLASH);
            if(result != BOAT_SUCCESS ){
                return result;
            }
            paramLength = UtilityGetLVData_L(lengthBytes);
            if(paramLength < 0){
                BoatLog(BOAT_LOG_NORMAL,"keypair data length err ");
                return BOAT_ERROR;
            }
            paramLengthLen = UtilityGetTLV_LL_from_len(paramLength);
            offset += (paramLengthLen + paramLength);
            keypairLength += (paramLengthLen + paramLength);
        }
        // all the keypairs'length after index keypair
        keypairData = BoatMalloc(keypairLength);
        if(NULL == keypairData){
            BoatLog(BOAT_LOG_NONE,"fail to malloc memory ");
            return BOAT_ERROR_COMMON_OUT_OF_MEMORY;
        }
        result = BoatReadSoftRotNvram(BOAT_STORE_KEYPAIR,offset_moveFrom,keypairData,keypairLength,BOAT_STORE_TYPE_FLASH);
        if(result != BOAT_SUCCESS){
            BoatFree(keypairData);
            BoatLog(BOAT_LOG_NONE,"read keypair data fail ");
            return BOAT_ERROR_STORAGE_FILE_READ_FAIL;
        }
        result = BoATStoreSoftRotNvram(BOAT_STORE_KEYPAIR,offset_moveTo,keypairData,keypairLength,BOAT_STORE_TYPE_FLASH);
        BoatFree(keypairData);
        if(result != BOAT_SUCCESS){
            /* recover keypairNum */
            result = BoATStoreSoftRotNvram(BOAT_STORE_KEYPAIR,offset,&keypairNum,sizeof(keypairNum),BOAT_STORE_TYPE_FLASH); 
            if(result != BOAT_SUCCESS){
            BoatLog(BOAT_LOG_NORMAL,"delete keypair fail ");
            return result;
            }
            BoatLog(BOAT_LOG_NONE,"store keypair data fail ");
            return BOAT_ERROR_STORAGE_FILE_WRITE_FAIL;
        }
    }
    }

    
    return result;
}


BOAT_RESULT BoatIotSdkInit(void)
{
    // BUINT32 i;
#if ((PROTOCOL_USE_ETHEREUM == 1) || (PROTOCOL_USE_PLATON == 1) || (PROTOCOL_USE_PLATONE == 1) || (PROTOCOL_USE_FISCOBCOS == 1) || (PROTOCOL_USE_VENACHAIN == 1))    
    cJSON_Hooks hooks;
#endif    
    
#if RPC_USE_LIBCURL == 1
    CURLcode curl_result;
#endif

#if ((PROTOCOL_USE_ETHEREUM == 1) || (PROTOCOL_USE_PLATON == 1) || (PROTOCOL_USE_PLATONE == 1) || (PROTOCOL_USE_FISCOBCOS == 1) || (PROTOCOL_USE_VENACHAIN == 1))
    hooks.malloc_fn = BoatMalloc;
    hooks.free_fn   = BoatFree;
    cJSON_InitHooks(&hooks);
#endif

	// For Multi-Thread Support: CreateMutex Here
    
#if RPC_USE_LIBCURL == 1
    curl_result = curl_global_init(CURL_GLOBAL_DEFAULT);
    
    if (curl_result != CURLE_OK)
    {
        BoatLog(BOAT_LOG_CRITICAL, "Unable to initialize curl.");
        return BOAT_ERROR_CURL_INIT_FAIL;
    }
#endif

    return BOAT_SUCCESS;
}


void BoatIotSdkDeInit(void)
{
    // BUINT32 i;
    

#if RPC_USE_LIBCURL == 1
    curl_global_cleanup();
#endif

// For Multi-Thread Support: DeleteMutex Here
}

