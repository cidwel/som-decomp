.setcpu "65816"
.segment "CODE"
.org $26F7
map_control_0d26f7:
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
