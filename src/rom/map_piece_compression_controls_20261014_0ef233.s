.setcpu "65816"
.segment "CODE"
.org $F233
map_control_0ef233:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $F8 ; row-distance/count
