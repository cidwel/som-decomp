; Numeric placement/transfer metadata, no pixel or tile bodies.
.setcpu "65816"
.segment "RODATA"
.org $FC7C
latent_dc_residue_numeric_20261013_scripts_cleanup:
    .byte $00, $00, $02 ; transfer 0: destination unit, source unit/sentinel, flags/count
    .byte $10, $02, $02 ; transfer 1: destination unit, source unit/sentinel, flags/count
    .byte $20, $04, $06 ; transfer 2: destination unit, source unit/sentinel, flags/count
    .byte $30, $0A, $06 ; transfer 3: destination unit, source unit/sentinel, flags/count
    .byte $44, $10, $06 ; transfer 4: destination unit, source unit/sentinel, flags/count
    .byte $54, $16, $06 ; transfer 5: destination unit, source unit/sentinel, flags/count
