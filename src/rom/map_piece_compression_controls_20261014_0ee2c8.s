.setcpu "65816"
.segment "CODE"
.org $E2C8
map_control_0ee2c8:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
