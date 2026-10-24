.setcpu "65816"
.segment "CODE"
.org $F240
control_dcf240:
    ; compression selector
    .byte $05
