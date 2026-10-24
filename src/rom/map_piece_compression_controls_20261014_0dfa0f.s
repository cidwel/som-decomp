.setcpu "65816"
.segment "CODE"
.org $FA0F
map_control_0dfa0f:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
