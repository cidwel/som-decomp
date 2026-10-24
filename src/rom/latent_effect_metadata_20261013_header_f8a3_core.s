; Numeric effect metadata only; no pointed payload.
.setcpu "65816"
.segment "RODATA"
.org $F8A3
latent_effect_metadata_20261013_header_f8a3_core:
    .byte $30 ; graphics_unit_count
    .word $6D80 ; graphics_source_pointer
    .byte $06 ; transfer_record_count
    .word $F847 ; transfer_record_pointer
    .byte $11 ; visual_field_10
    .byte $03 ; visual_fields_12_14
    .word $FD80 ; sprite_record_D1_pointer
    .byte $03 ; visual_fields_1E_20
