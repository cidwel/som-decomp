; Numeric placement/transfer metadata, no pixel or tile bodies.
.setcpu "65816"
.segment "RODATA"
.org $FC6A
latent_dc_residue_numeric_20261013_scripts_setup:
    .byte $00, $00, $82 ; transfer 0: destination unit, source unit/sentinel, flags/count
    .byte $10, $02, $82 ; transfer 1: destination unit, source unit/sentinel, flags/count
    .byte $20, $04, $86 ; transfer 2: destination unit, source unit/sentinel, flags/count
    .byte $30, $0A, $86 ; transfer 3: destination unit, source unit/sentinel, flags/count
    .byte $44, $10, $86 ; transfer 4: destination unit, source unit/sentinel, flags/count
    .byte $54, $16, $86 ; transfer 5: destination unit, source unit/sentinel, flags/count
