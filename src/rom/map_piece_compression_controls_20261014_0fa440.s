.setcpu "65816"
.segment "CODE"
.org $A440
map_control_0fa440:
    .byte $DE ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $D7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
