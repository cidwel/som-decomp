; Native7F resource descriptors, no resource payload; docs/boss-resource-descriptor-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BD4A
boss_resource_1f:
boss_resource_1f_source_bank:
    .byte $DA
boss_resource_1f_ram_destination_bank:
    .byte $7F
boss_resource_1f_source_offset:
    .word $1000
boss_resource_1f_destination_offset:
    .word $4000
boss_resource_1f_expansion_count:
    .word $3400
boss_resource_20:
boss_resource_20_source_bank:
    .byte $DA
boss_resource_20_ram_destination_bank:
    .byte $7F
boss_resource_20_source_offset:
    .word $37F8
boss_resource_20_destination_offset:
    .word $4000
boss_resource_20_expansion_count:
    .word $4000
