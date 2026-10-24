; Numeric effect metadata only; no pointed payload.
.setcpu "65816"
.segment "RODATA"
.org $FC32
latent_resource_format_next_20261013_header_fc32_core:
    .byte $35 ; graphics_unit_count
    .word $8148 ; graphics_source_pointer
    .byte $0F ; transfer_record_count
    .word $FC05 ; transfer_record_pointer
    .byte $03 ; visual_field_10
    .byte $04 ; visual_fields_12_14
    .word $FB50 ; sprite_record_D1_pointer
    .byte $04 ; visual_fields_1E_20
