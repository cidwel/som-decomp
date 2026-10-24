; Typed gameplay records; docs/combat-attribute-numeric-source.md.
; unk22/flags25/unk9 retain explicitly unresolved field semantics.
.setcpu "65816"
.segment "CODE"
.org $3ED0
armor_attribute_records:
armors_record_000:
    .byte 64 ; flags
    .byte 0 ; defense
    .byte 0 ; evade
    .byte 0 ; mdef
    .byte 0 ; mev
    .byte 224 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_001:
    .byte 64 ; flags
    .byte 2 ; defense
    .byte 23 ; evade
    .byte 2 ; mdef
    .byte 23 ; mev
    .byte 128 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_002:
    .byte 64 ; flags
    .byte 3 ; defense
    .byte 23 ; evade
    .byte 3 ; mdef
    .byte 23 ; mev
    .byte 64 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_003:
    .byte 64 ; flags
    .byte 5 ; defense
    .byte 23 ; evade
    .byte 5 ; mdef
    .byte 23 ; mev
    .byte 32 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_004:
    .byte 64 ; flags
    .byte 7 ; defense
    .byte 23 ; evade
    .byte 7 ; mdef
    .byte 23 ; mev
    .byte 128 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_005:
    .byte 64 ; flags
    .byte 10 ; defense
    .byte 23 ; evade
    .byte 10 ; mdef
    .byte 23 ; mev
    .byte 96 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_006:
    .byte 64 ; flags
    .byte 13 ; defense
    .byte 23 ; evade
    .byte 13 ; mdef
    .byte 23 ; mev
    .byte 128 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_007:
    .byte 64 ; flags
    .byte 17 ; defense
    .byte 23 ; evade
    .byte 17 ; mdef
    .byte 23 ; mev
    .byte 96 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_008:
    .byte 64 ; flags
    .byte 21 ; defense
    .byte 23 ; evade
    .byte 21 ; mdef
    .byte 23 ; mev
    .byte 224 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_009:
    .byte 72 ; flags
    .byte 26 ; defense
    .byte 23 ; evade
    .byte 26 ; mdef
    .byte 23 ; mev
    .byte 96 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_010:
    .byte 64 ; flags
    .byte 32 ; defense
    .byte 23 ; evade
    .byte 32 ; mdef
    .byte 23 ; mev
    .byte 224 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_011:
    .byte 66 ; flags
    .byte 38 ; defense
    .byte 23 ; evade
    .byte 38 ; mdef
    .byte 23 ; mev
    .byte 160 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_012:
    .byte 64 ; flags
    .byte 46 ; defense
    .byte 23 ; evade
    .byte 46 ; mdef
    .byte 23 ; mev
    .byte 64 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_013:
    .byte 65 ; flags
    .byte 55 ; defense
    .byte 23 ; evade
    .byte 55 ; mdef
    .byte 23 ; mev
    .byte 224 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_014:
    .byte 64 ; flags
    .byte 66 ; defense
    .byte 23 ; evade
    .byte 66 ; mdef
    .byte 23 ; mev
    .byte 224 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_015:
    .byte 64 ; flags
    .byte 78 ; defense
    .byte 23 ; evade
    .byte 78 ; mdef
    .byte 23 ; mev
    .byte 96 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_016:
    .byte 64 ; flags
    .byte 140 ; defense
    .byte 23 ; evade
    .byte 140 ; mdef
    .byte 23 ; mev
    .byte 224 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_017:
    .byte 64 ; flags
    .byte 142 ; defense
    .byte 23 ; evade
    .byte 143 ; mdef
    .byte 23 ; mev
    .byte 224 ; equip_mask
    .byte 0 ; element_resist
    .word 64 ; status_immunity
    .byte 0 ; unk9
armors_record_018:
    .byte 67 ; flags
    .byte 143 ; defense
    .byte 23 ; evade
    .byte 142 ; mdef
    .byte 23 ; mev
    .byte 96 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_019:
    .byte 88 ; flags
    .byte 145 ; defense
    .byte 23 ; evade
    .byte 145 ; mdef
    .byte 23 ; mev
    .byte 128 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_020:
    .byte 67 ; flags
    .byte 150 ; defense
    .byte 23 ; evade
    .byte 150 ; mdef
    .byte 23 ; mev
    .byte 96 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_021:
    .byte 64 ; flags
    .byte 0 ; defense
    .byte 0 ; evade
    .byte 0 ; mdef
    .byte 0 ; mev
    .byte 224 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_022:
    .byte 64 ; flags
    .byte 3 ; defense
    .byte 37 ; evade
    .byte 1 ; mdef
    .byte 15 ; mev
    .byte 128 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_023:
    .byte 64 ; flags
    .byte 4 ; defense
    .byte 37 ; evade
    .byte 2 ; mdef
    .byte 15 ; mev
    .byte 64 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_024:
    .byte 64 ; flags
    .byte 7 ; defense
    .byte 37 ; evade
    .byte 4 ; mdef
    .byte 15 ; mev
    .byte 32 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_025:
    .byte 64 ; flags
    .byte 10 ; defense
    .byte 37 ; evade
    .byte 6 ; mdef
    .byte 15 ; mev
    .byte 224 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_026:
    .byte 64 ; flags
    .byte 13 ; defense
    .byte 37 ; evade
    .byte 8 ; mdef
    .byte 15 ; mev
    .byte 160 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_027:
    .byte 64 ; flags
    .byte 17 ; defense
    .byte 37 ; evade
    .byte 10 ; mdef
    .byte 15 ; mev
    .byte 64 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_028:
    .byte 64 ; flags
    .byte 22 ; defense
    .byte 37 ; evade
    .byte 13 ; mdef
    .byte 15 ; mev
    .byte 224 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_029:
    .byte 64 ; flags
    .byte 28 ; defense
    .byte 37 ; evade
    .byte 16 ; mdef
    .byte 15 ; mev
    .byte 96 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_030:
    .byte 64 ; flags
    .byte 34 ; defense
    .byte 37 ; evade
    .byte 20 ; mdef
    .byte 15 ; mev
    .byte 224 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_031:
    .byte 64 ; flags
    .byte 43 ; defense
    .byte 37 ; evade
    .byte 24 ; mdef
    .byte 15 ; mev
    .byte 224 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_032:
    .byte 64 ; flags
    .byte 52 ; defense
    .byte 37 ; evade
    .byte 29 ; mdef
    .byte 15 ; mev
    .byte 160 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_033:
    .byte 64 ; flags
    .byte 64 ; defense
    .byte 37 ; evade
    .byte 35 ; mdef
    .byte 15 ; mev
    .byte 64 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_034:
    .byte 64 ; flags
    .byte 78 ; defense
    .byte 37 ; evade
    .byte 41 ; mdef
    .byte 15 ; mev
    .byte 224 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_035:
    .byte 64 ; flags
    .byte 95 ; defense
    .byte 37 ; evade
    .byte 49 ; mdef
    .byte 15 ; mev
    .byte 160 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_036:
    .byte 64 ; flags
    .byte 115 ; defense
    .byte 37 ; evade
    .byte 57 ; mdef
    .byte 15 ; mev
    .byte 64 ; equip_mask
    .byte 0 ; element_resist
    .word 8208 ; status_immunity
    .byte 0 ; unk9
armors_record_037:
    .byte 64 ; flags
    .byte 139 ; defense
    .byte 37 ; evade
    .byte 67 ; mdef
    .byte 15 ; mev
    .byte 224 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_038:
    .byte 64 ; flags
    .byte 240 ; defense
    .byte 37 ; evade
    .byte 90 ; mdef
    .byte 15 ; mev
    .byte 224 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_039:
    .byte 64 ; flags
    .byte 243 ; defense
    .byte 37 ; evade
    .byte 93 ; mdef
    .byte 15 ; mev
    .byte 96 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_040:
    .byte 80 ; flags
    .byte 245 ; defense
    .byte 37 ; evade
    .byte 95 ; mdef
    .byte 15 ; mev
    .byte 128 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_041:
    .byte 68 ; flags
    .byte 250 ; defense
    .byte 37 ; evade
    .byte 100 ; mdef
    .byte 15 ; mev
    .byte 96 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_042:
    .byte 64 ; flags
    .byte 0 ; defense
    .byte 0 ; evade
    .byte 0 ; mdef
    .byte 0 ; mev
    .byte 224 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_043:
    .byte 72 ; flags
    .byte 100 ; defense
    .byte 15 ; evade
    .byte 250 ; mdef
    .byte 37 ; mev
    .byte 224 ; equip_mask
    .byte 0 ; element_resist
    .word 9088 ; status_immunity
    .byte 0 ; unk9
armors_record_044:
    .byte 64 ; flags
    .byte 2 ; defense
    .byte 15 ; evade
    .byte 4 ; mdef
    .byte 37 ; mev
    .byte 224 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_045:
    .byte 80 ; flags
    .byte 4 ; defense
    .byte 15 ; evade
    .byte 7 ; mdef
    .byte 37 ; mev
    .byte 224 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_046:
    .byte 64 ; flags
    .byte 6 ; defense
    .byte 15 ; evade
    .byte 10 ; mdef
    .byte 37 ; mev
    .byte 224 ; equip_mask
    .byte 0 ; element_resist
    .word 8192 ; status_immunity
    .byte 0 ; unk9
armors_record_047:
    .byte 72 ; flags
    .byte 8 ; defense
    .byte 15 ; evade
    .byte 13 ; mdef
    .byte 37 ; mev
    .byte 224 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_048:
    .byte 65 ; flags
    .byte 10 ; defense
    .byte 15 ; evade
    .byte 17 ; mdef
    .byte 37 ; mev
    .byte 224 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_049:
    .byte 64 ; flags
    .byte 13 ; defense
    .byte 15 ; evade
    .byte 22 ; mdef
    .byte 37 ; mev
    .byte 224 ; equip_mask
    .byte 0 ; element_resist
    .word 4 ; status_immunity
    .byte 0 ; unk9
armors_record_050:
    .byte 64 ; flags
    .byte 16 ; defense
    .byte 15 ; evade
    .byte 28 ; mdef
    .byte 37 ; mev
    .byte 224 ; equip_mask
    .byte 0 ; element_resist
    .word 32 ; status_immunity
    .byte 0 ; unk9
armors_record_051:
    .byte 64 ; flags
    .byte 20 ; defense
    .byte 15 ; evade
    .byte 34 ; mdef
    .byte 37 ; mev
    .byte 224 ; equip_mask
    .byte 0 ; element_resist
    .word 8208 ; status_immunity
    .byte 0 ; unk9
armors_record_052:
    .byte 64 ; flags
    .byte 24 ; defense
    .byte 15 ; evade
    .byte 43 ; mdef
    .byte 37 ; mev
    .byte 224 ; equip_mask
    .byte 0 ; element_resist
    .word 64 ; status_immunity
    .byte 0 ; unk9
armors_record_053:
    .byte 64 ; flags
    .byte 29 ; defense
    .byte 15 ; evade
    .byte 52 ; mdef
    .byte 37 ; mev
    .byte 224 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_054:
    .byte 67 ; flags
    .byte 35 ; defense
    .byte 15 ; evade
    .byte 64 ; mdef
    .byte 37 ; mev
    .byte 224 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_055:
    .byte 64 ; flags
    .byte 41 ; defense
    .byte 15 ; evade
    .byte 78 ; mdef
    .byte 37 ; mev
    .byte 224 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_056:
    .byte 80 ; flags
    .byte 90 ; defense
    .byte 15 ; evade
    .byte 240 ; mdef
    .byte 37 ; mev
    .byte 224 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_057:
    .byte 72 ; flags
    .byte 91 ; defense
    .byte 15 ; evade
    .byte 241 ; mdef
    .byte 37 ; mev
    .byte 224 ; equip_mask
    .byte 0 ; element_resist
    .word 4 ; status_immunity
    .byte 0 ; unk9
armors_record_058:
    .byte 64 ; flags
    .byte 92 ; defense
    .byte 15 ; evade
    .byte 242 ; mdef
    .byte 37 ; mev
    .byte 224 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_059:
    .byte 64 ; flags
    .byte 93 ; defense
    .byte 15 ; evade
    .byte 243 ; mdef
    .byte 37 ; mev
    .byte 224 ; equip_mask
    .byte 0 ; element_resist
    .word 4096 ; status_immunity
    .byte 0 ; unk9
armors_record_060:
    .byte 64 ; flags
    .byte 94 ; defense
    .byte 15 ; evade
    .byte 244 ; mdef
    .byte 37 ; mev
    .byte 224 ; equip_mask
    .byte 0 ; element_resist
    .word 16416 ; status_immunity
    .byte 0 ; unk9
armors_record_061:
    .byte 64 ; flags
    .byte 95 ; defense
    .byte 15 ; evade
    .byte 245 ; mdef
    .byte 37 ; mev
    .byte 224 ; equip_mask
    .byte 0 ; element_resist
    .word 64 ; status_immunity
    .byte 0 ; unk9
armors_record_062:
    .byte 64 ; flags
    .byte 1 ; defense
    .byte 15 ; evade
    .byte 3 ; mdef
    .byte 37 ; mev
    .byte 192 ; equip_mask
    .byte 0 ; element_resist
    .word 0 ; status_immunity
    .byte 0 ; unk9
armors_record_063:
    .byte 255 ; flags
    .byte 255 ; defense
    .byte 255 ; evade
    .byte 255 ; mdef
    .byte 255 ; mev
    .byte 255 ; equip_mask
    .byte 255 ; element_resist
    .word 65535 ; status_immunity
    .byte 255 ; unk9
