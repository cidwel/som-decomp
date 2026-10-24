; Numeric effect metadata only; no pointed payload.
.setcpu "65816"
.segment "RODATA"
.org $F847
latent_effect_metadata_20261013_transfers_f847:
    .byte $00, $00, $29 ; transfer record 0: destination unit, source unit/sentinel, flags and count
    .byte $1D, $FF, $03 ; transfer record 1: destination unit, source unit/sentinel, flags and count
    .byte $29, $FF, $15 ; transfer record 2: destination unit, source unit/sentinel, flags and count
    .byte $36, $29, $03 ; transfer record 3: destination unit, source unit/sentinel, flags and count
    .byte $2A, $1D, $03 ; transfer record 4: destination unit, source unit/sentinel, flags and count
    .byte $3A, $2D, $03 ; transfer record 5: destination unit, source unit/sentinel, flags and count
