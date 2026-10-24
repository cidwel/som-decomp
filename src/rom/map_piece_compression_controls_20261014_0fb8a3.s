.setcpu "65816"
.segment "CODE"
.org $B8A3
map_control_0fb8a3:
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
