.setcpu "65816"
.segment "CODE"
.org $7B20
map_control_0e7b20:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
