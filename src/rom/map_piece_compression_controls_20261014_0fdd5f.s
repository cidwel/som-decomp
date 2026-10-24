.setcpu "65816"
.segment "CODE"
.org $DD5F
map_control_0fdd5f:
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
