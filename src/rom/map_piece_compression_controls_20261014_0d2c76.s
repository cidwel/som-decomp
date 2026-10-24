.setcpu "65816"
.segment "CODE"
.org $2C76
map_control_0d2c76:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
