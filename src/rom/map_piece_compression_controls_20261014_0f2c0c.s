.setcpu "65816"
.segment "CODE"
.org $2C0C
map_control_0f2c0c:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
