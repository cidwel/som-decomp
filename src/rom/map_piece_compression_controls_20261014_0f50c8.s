.setcpu "65816"
.segment "CODE"
.org $50C8
map_control_0f50c8:
    .byte $E7 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
