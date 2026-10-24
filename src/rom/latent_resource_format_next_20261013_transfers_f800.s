; Numeric effect metadata only; no pointed payload.
.setcpu "65816"
.segment "RODATA"
.org $F800
latent_resource_format_next_20261013_transfers_f800:
    .byte $00, $00, $02 ; descriptor 0: destination unit, source unit/sentinel, flags and count
    .byte $10, $02, $02 ; descriptor 1: destination unit, source unit/sentinel, flags and count
    .byte $02, $04, $02 ; descriptor 2: destination unit, source unit/sentinel, flags and count
    .byte $12, $06, $02 ; descriptor 3: destination unit, source unit/sentinel, flags and count
    .byte $04, $08, $02 ; descriptor 4: destination unit, source unit/sentinel, flags and count
    .byte $14, $0A, $02 ; descriptor 5: destination unit, source unit/sentinel, flags and count
    .byte $06, $0C, $02 ; descriptor 6: destination unit, source unit/sentinel, flags and count
    .byte $16, $0E, $02 ; descriptor 7: destination unit, source unit/sentinel, flags and count
    .byte $08, $10, $02 ; descriptor 8: destination unit, source unit/sentinel, flags and count
    .byte $18, $12, $02 ; descriptor 9: destination unit, source unit/sentinel, flags and count
