; Numeric sprite control metadata; no graphical payload.
.setcpu "65816"
.segment "RODATA"
.org $6028
warm_child_metadata_6028:
    .byte $00, $00 ; x-offset, y-offset
    .byte $00, $08 ; x-offset, y-offset
    .byte $00, $10 ; x-offset, y-offset
    .byte $08, $00 ; x-offset, y-offset
    .byte $08, $08 ; x-offset, y-offset
    .byte $08, $10 ; x-offset, y-offset
    .byte $10, $00 ; x-offset, y-offset
    .byte $10, $08 ; x-offset, y-offset
    .byte $10, $10 ; x-offset, y-offset
