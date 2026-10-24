.setcpu "65816"
.segment "CODE"
.org $F3BC
map_control_0df3bc:
    .byte $D9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E3 ; previous-row copy count
