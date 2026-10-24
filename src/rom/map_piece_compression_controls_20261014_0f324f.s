.setcpu "65816"
.segment "CODE"
.org $324F
map_control_0f324f:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
