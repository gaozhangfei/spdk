/*   SPDX-License-Identifier: BSD-3-Clause
 *   Copyright (C) 2022 Intel Corporation.
 *   All rights reserved.
 */

#ifndef FTL_SB_V3_H
#define FTL_SB_V3_H

#include "spdk/uuid.h"
#include "ftl_sb_common.h"
#include "ftl_sb_current.h"

struct spdk_ftl_dev;
struct ftl_layout_region;
union ftl_superblock_ver;

bool ftl_superblock_v3_check_magic(union ftl_superblock_ver *sb_ver);

bool ftl_superblock_v3_md_layout_is_empty(union ftl_superblock_ver *sb_ver);

int ftl_superblock_v3_md_layout_build(struct spdk_ftl_dev *dev);

int ftl_superblock_v3_md_layout_load_all(struct spdk_ftl_dev *dev);

int ftl_superblock_v3_md_layout_upgrade_region(struct spdk_ftl_dev *dev,
		struct ftl_layout_region *reg, uint32_t new_version);

void ftl_superblock_v3_md_layout_dump(struct spdk_ftl_dev *dev);

#endif /* FTL_SB_V3_H */
