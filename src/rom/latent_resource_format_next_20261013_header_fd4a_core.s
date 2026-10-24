; Numeric effect metadata only; no pointed payload.
.setcpu "65816"
.segment "RODATA"
.org $FD4A
latent_resource_format_next_20261013_header_fd4a_core:
    .byte $14 ; graphics_unit_count
    .word $9F30 ; graphics_source_pointer
    .byte $14 ; transfer_record_count
    .word $FD0E ; transfer_record_pointer
    .byte $21 ; visual_field_10
    .byte $03 ; visual_fields_12_14
    .word $FC90 ; sprite_record_D1_pointer
    .byte $03 ; visual_fields_1E_20
