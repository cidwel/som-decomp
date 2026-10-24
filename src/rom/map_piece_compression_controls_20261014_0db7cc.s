.setcpu "65816"
.segment "CODE"
.org $B7CC
map_control_0db7cc:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $D1 ; same-value copy count/distance
