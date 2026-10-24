.setcpu "65816"
.segment "CODE"
.org $2C51
map_control_0d2c51:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
