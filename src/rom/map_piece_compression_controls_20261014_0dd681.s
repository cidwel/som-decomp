.setcpu "65816"
.segment "CODE"
.org $D681
map_control_0dd681:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
