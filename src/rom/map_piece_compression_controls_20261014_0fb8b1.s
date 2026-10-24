.setcpu "65816"
.segment "CODE"
.org $B8B1
map_control_0fb8b1:
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
