; Numeric effect metadata only; no pointed payload.
.setcpu "65816"
.segment "RODATA"
.org $FAFD
latent_effect_metadata_20261013_header_fafd_core:
    .byte $25 ; graphics_unit_count
    .word $A938 ; graphics_source_pointer
    .byte $26 ; transfer_record_count
    .word $FA8B ; transfer_record_pointer
    .byte $20 ; visual_field_10
    .byte $00 ; visual_fields_12_14
    .word $FBDC ; sprite_record_D1_pointer
    .byte $04 ; visual_fields_1E_20
