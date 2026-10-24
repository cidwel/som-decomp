.setcpu "65816"
.segment "CODE"
.org $B8C7
map_control_0fb8c7:
    .byte $D5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $42 ; row-distance/count
