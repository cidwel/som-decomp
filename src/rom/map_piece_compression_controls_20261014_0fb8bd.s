.setcpu "65816"
.segment "CODE"
.org $B8BD
map_control_0fb8bd:
    .byte $E0 ; previous-row copy escape
    .byte $40 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
