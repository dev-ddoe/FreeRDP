/**
 * FreeRDP: A Remote Desktop Protocol Implementation
 * Bulk Compression
 *
 * Copyright 2014 Marc-Andre Moreau <marcandre.moreau@gmail.com>
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
 */

#ifndef FREERDP_LIB_CORE_BULK_H
#define FREERDP_LIB_CORE_BULK_H

typedef struct rdp_bulk rdpBulk;

#include <freerdp/api.h>
#include <freerdp/freerdp.h>

#define BULK_COMPRESSION_FLAGS_MASK 0xE0
#define BULK_COMPRESSION_TYPE_MASK 0x0F

FREERDP_LOCAL UINT16 bulk_compression_max_size(rdpBulk* WINPR_RESTRICT bulk);

FREERDP_LOCAL int bulk_decompress(rdpBulk* WINPR_RESTRICT bulk, const BYTE* WINPR_RESTRICT pSrcData,
                                  UINT32 SrcSize, const BYTE** WINPR_RESTRICT ppDstData,
                                  UINT32* WINPR_RESTRICT pDstSize, UINT32 flags);
FREERDP_LOCAL int bulk_compress(rdpBulk* WINPR_RESTRICT bulk, const BYTE* WINPR_RESTRICT pSrcData,
                                UINT32 SrcSize, const BYTE** WINPR_RESTRICT ppDstData,
                                UINT32* WINPR_RESTRICT pDstSize, UINT32* WINPR_RESTRICT pFlags);

FREERDP_LOCAL void bulk_reset(rdpBulk* WINPR_RESTRICT bulk);

FREERDP_LOCAL void bulk_free(rdpBulk* bulk);

WINPR_ATTR_MALLOC(bulk_free, 1)
FREERDP_LOCAL rdpBulk* bulk_new(rdpContext* context);

#endif /* FREERDP_LIB_CORE_BULK_H */
