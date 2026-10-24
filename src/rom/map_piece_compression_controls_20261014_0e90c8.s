.setcpu "65816"
.segment "CODE"
.org $90C8
map_control_0e90c8:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $C5 ; same-value copy count/distance
