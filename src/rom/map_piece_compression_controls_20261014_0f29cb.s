.setcpu "65816"
.segment "CODE"
.org $29CB
map_control_0f29cb:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
