.setcpu "65816"
.segment "CODE"
.org $B330
map_control_0db330:
    .byte $E3 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
