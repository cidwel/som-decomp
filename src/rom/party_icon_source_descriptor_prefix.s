; Numeric packed source addresses only; no pointed tile payload.
.setcpu "65816"
.segment "RODATA"
.org $C600
.macro icon_source_descriptor tile_unit, bank_selector, ignored_bits
    .word tile_unit | (bank_selector << 12) | ignored_bits
.endmacro
party_icon_source_descriptor_prefix:
party_icon_source_descriptor_slot_00:
    icon_source_descriptor $0ED, 0, $0000 ; corner 0
    icon_source_descriptor $0EE, 0, $0000 ; corner 1
    icon_source_descriptor $0EF, 0, $0000 ; corner 2
    icon_source_descriptor $0F2, 0, $0000 ; corner 3
party_icon_source_descriptor_slot_01:
    icon_source_descriptor $4F6, 0, $0000 ; corner 0
    icon_source_descriptor $4F7, 0, $0000 ; corner 1
    icon_source_descriptor $4F8, 0, $0000 ; corner 2
    icon_source_descriptor $4F9, 0, $0000 ; corner 3
party_icon_source_descriptor_slot_02:
    icon_source_descriptor $001, 1, $0000 ; corner 0
    icon_source_descriptor $0F5, 1, $0000 ; corner 1
    icon_source_descriptor $003, 1, $0000 ; corner 2
    icon_source_descriptor $0F6, 1, $0000 ; corner 3
party_icon_source_descriptor_slot_03:
    icon_source_descriptor $308, 7, $0000 ; corner 0
    icon_source_descriptor $309, 7, $0000 ; corner 1
    icon_source_descriptor $30A, 7, $0000 ; corner 2
    icon_source_descriptor $30B, 7, $0000 ; corner 3
party_icon_source_descriptor_slot_04:
    icon_source_descriptor $310, 7, $0000 ; corner 0
    icon_source_descriptor $311, 7, $0000 ; corner 1
    icon_source_descriptor $312, 7, $0000 ; corner 2
    icon_source_descriptor $313, 7, $0000 ; corner 3
party_icon_source_descriptor_slot_05:
    icon_source_descriptor $314, 7, $0000 ; corner 0
    icon_source_descriptor $315, 7, $0000 ; corner 1
    icon_source_descriptor $317, 7, $0000 ; corner 2
    icon_source_descriptor $318, 7, $0000 ; corner 3
party_icon_source_descriptor_slot_06:
    icon_source_descriptor $32A, 7, $0000 ; corner 0
    icon_source_descriptor $32B, 7, $0000 ; corner 1
    icon_source_descriptor $32C, 7, $0000 ; corner 2
    icon_source_descriptor $32D, 7, $0000 ; corner 3
party_icon_source_descriptor_slot_07:
    icon_source_descriptor $2C8, 7, $0000 ; corner 0
    icon_source_descriptor $2C9, 7, $0000 ; corner 1
    icon_source_descriptor $2CA, 7, $0000 ; corner 2
    icon_source_descriptor $2CB, 7, $0000 ; corner 3
party_icon_source_descriptor_slot_08:
    icon_source_descriptor $2D8, 7, $0000 ; corner 0
    icon_source_descriptor $2D9, 7, $0000 ; corner 1
    icon_source_descriptor $2DB, 7, $0000 ; corner 2
    icon_source_descriptor $2DC, 7, $0000 ; corner 3
party_icon_source_descriptor_slot_09:
    icon_source_descriptor $2E6, 7, $0000 ; corner 0
    icon_source_descriptor $2E7, 7, $0000 ; corner 1
    icon_source_descriptor $2E8, 7, $0000 ; corner 2
    icon_source_descriptor $2E9, 7, $0000 ; corner 3
party_icon_source_descriptor_slot_0a:
    icon_source_descriptor $2F7, 7, $0000 ; corner 0
    icon_source_descriptor $2F8, 7, $0000 ; corner 1
    icon_source_descriptor $2F9, 7, $0000 ; corner 2
    icon_source_descriptor $2FA, 7, $0000 ; corner 3
party_icon_source_descriptor_slot_0b:
    icon_source_descriptor $2F7, 7, $0000 ; corner 0
    icon_source_descriptor $2F8, 7, $0000 ; corner 1
    icon_source_descriptor $2FC, 7, $0000 ; corner 2
    icon_source_descriptor $2FD, 7, $0000 ; corner 3
party_icon_source_descriptor_slot_0c:
    icon_source_descriptor $306, 7, $0000 ; corner 0
    icon_source_descriptor $307, 7, $0000 ; corner 1
    icon_source_descriptor $2F3, 7, $0000 ; corner 2
    icon_source_descriptor $2F4, 7, $0000 ; corner 3
party_icon_source_descriptor_slot_0d:
    icon_source_descriptor $238, 7, $0000 ; corner 0
    icon_source_descriptor $239, 7, $0000 ; corner 1
    icon_source_descriptor $248, 7, $0000 ; corner 2
    icon_source_descriptor $249, 7, $0000 ; corner 3
party_icon_source_descriptor_slot_0e:
    icon_source_descriptor $266, 7, $0000 ; corner 0
    icon_source_descriptor $267, 7, $0000 ; corner 1
    icon_source_descriptor $276, 7, $0000 ; corner 2
    icon_source_descriptor $277, 7, $0000 ; corner 3
party_icon_source_descriptor_slot_0f:
    icon_source_descriptor $2B7, 7, $0000 ; corner 0
    icon_source_descriptor $2B8, 7, $0000 ; corner 1
    icon_source_descriptor $2B9, 7, $0000 ; corner 2
    icon_source_descriptor $2BA, 7, $0000 ; corner 3
party_icon_source_descriptor_slot_10:
    icon_source_descriptor $000, 0, $0000 ; corner 0
    icon_source_descriptor $000, 0, $0000 ; corner 1
    icon_source_descriptor $000, 0, $0000 ; corner 2
    icon_source_descriptor $000, 0, $0000 ; corner 3
party_icon_source_descriptor_slot_11:
    icon_source_descriptor $000, 0, $0000 ; corner 0
    icon_source_descriptor $700, 0, $0000 ; corner 1
    icon_source_descriptor $703, 0, $0000 ; corner 2
    icon_source_descriptor $703, 0, $0000 ; corner 3
party_icon_source_descriptor_slot_12:
    icon_source_descriptor $000, 0, $0000 ; corner 0
    icon_source_descriptor $000, 0, $0000 ; corner 1
    icon_source_descriptor $000, 0, $0000 ; corner 2
    icon_source_descriptor $000, 0, $0000 ; corner 3
party_icon_source_descriptor_slot_13:
    icon_source_descriptor $000, 0, $0000 ; corner 0
    icon_source_descriptor $700, 0, $0000 ; corner 1
    icon_source_descriptor $703, 0, $0000 ; corner 2
    icon_source_descriptor $702, 0, $0000 ; corner 3
party_icon_source_descriptor_slot_14:
    icon_source_descriptor $000, 0, $0000 ; corner 0
    icon_source_descriptor $000, 0, $0000 ; corner 1
    icon_source_descriptor $000, 0, $0000 ; corner 2
    icon_source_descriptor $000, 0, $0000 ; corner 3
party_icon_source_descriptor_slot_15:
    icon_source_descriptor $000, 0, $0000 ; corner 0
    icon_source_descriptor $000, 6, $8000 ; corner 1
    icon_source_descriptor $080, 2, $8000 ; corner 2
    icon_source_descriptor $000, 6, $8000 ; corner 3
party_icon_source_descriptor_slot_16:
    icon_source_descriptor $000, 0, $0000 ; corner 0
    icon_source_descriptor $000, 0, $0000 ; corner 1
    icon_source_descriptor $000, 0, $0000 ; corner 2
    icon_source_descriptor $000, 0, $0000 ; corner 3
