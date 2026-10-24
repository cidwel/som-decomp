.setcpu "65816"
.segment "CODE"
.org $331C
map_control_0c331c:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
