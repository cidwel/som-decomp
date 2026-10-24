.setcpu "65816"
.segment "CODE"
.org $9A2C
map_control_0d9a2c:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
