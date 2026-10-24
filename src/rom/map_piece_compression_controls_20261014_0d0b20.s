.setcpu "65816"
.segment "CODE"
.org $0B20
map_control_0d0b20:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
