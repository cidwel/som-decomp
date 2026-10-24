.setcpu "65816"
.segment "CODE"
.org $2C42
map_control_0e2c42:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
