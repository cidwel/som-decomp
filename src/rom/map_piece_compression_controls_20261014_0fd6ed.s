.setcpu "65816"
.segment "CODE"
.org $D6ED
map_control_0fd6ed:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
