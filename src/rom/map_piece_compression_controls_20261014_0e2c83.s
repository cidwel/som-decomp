.setcpu "65816"
.segment "CODE"
.org $2C83
map_control_0e2c83:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
