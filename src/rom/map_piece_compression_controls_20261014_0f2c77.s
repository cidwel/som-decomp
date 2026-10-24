.setcpu "65816"
.segment "CODE"
.org $2C77
map_control_0f2c77:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
