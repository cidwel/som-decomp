; Numeric effect metadata only; no pointed payload.
.setcpu "65816"
.segment "RODATA"
.org $FE72
latent_resource_format_next_20261013_header_fe72_core:
    .byte $0A ; graphics_unit_count
    .word $5238 ; graphics_source_pointer
    .byte $08 ; transfer_record_count
    .word $FE5A ; transfer_record_pointer
    .byte $03 ; visual_field_10
    .byte $04 ; visual_fields_12_14
    .word $FD30 ; sprite_record_D1_pointer
    .byte $04 ; visual_fields_1E_20
