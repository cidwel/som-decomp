.setcpu "65816"
.segment "CODE"
.org $5CC5
map_control_0f5cc5:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
