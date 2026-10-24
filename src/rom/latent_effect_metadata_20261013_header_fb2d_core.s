; Numeric effect metadata only; no pointed payload.
.setcpu "65816"
.segment "RODATA"
.org $FB2D
latent_effect_metadata_20261013_header_fb2d_core:
    .byte $25 ; graphics_unit_count
    .word $A938 ; graphics_source_pointer
    .byte $26 ; transfer_record_count
    .word $FA8B ; transfer_record_pointer
    .byte $70 ; visual_field_10
    .byte $00 ; visual_fields_12_14
    .word $FCCC ; sprite_record_D1_pointer
    .byte $01 ; visual_fields_1E_20
