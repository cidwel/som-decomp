; Numeric state IDs and FF terminators only; no narrative/script command payload.
.setcpu "65816"
.segment "RODATA"
.org $DD57
latent_shape_producer_next_20261013_sequence_dd57:
latent_shape_producer_next_20261013_root_dd57:
    .byte $00 ; state index 0
    .byte $01 ; state index 1
    .byte $FF ; sequence terminator
latent_shape_producer_next_20261013_root_dd5a:
    .byte $03 ; state index 3
    .byte $FF ; sequence terminator
