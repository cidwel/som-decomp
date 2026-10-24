.setcpu "65816"
.segment "CODE"
.org $7AD9
map_control_0f7ad9:
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
