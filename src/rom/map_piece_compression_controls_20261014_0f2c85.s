.setcpu "65816"
.segment "CODE"
.org $2C85
map_control_0f2c85:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
