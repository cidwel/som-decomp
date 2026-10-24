.setcpu "65816"
.segment "CODE"
.org $2C4A
map_control_0f2c4a:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
