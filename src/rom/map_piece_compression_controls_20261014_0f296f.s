.setcpu "65816"
.segment "CODE"
.org $296F
map_control_0f296f:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
