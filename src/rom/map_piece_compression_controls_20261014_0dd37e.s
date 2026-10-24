.setcpu "65816"
.segment "CODE"
.org $D37E
map_control_0dd37e:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
