; Numeric effect metadata only; no pointed payload.
.setcpu "65816"
.segment "RODATA"
.org $F81E
latent_resource_format_next_20261013_header_f81e_core:
    .byte $14 ; graphics_unit_count
    .word $A758 ; graphics_source_pointer
    .byte $0A ; transfer_record_count
    .word $F800 ; transfer_record_pointer
    .byte $21 ; visual_field_10
    .byte $02 ; visual_fields_12_14
    .word $FC0E ; sprite_record_D1_pointer
    .byte $1E ; visual_fields_1E_20
