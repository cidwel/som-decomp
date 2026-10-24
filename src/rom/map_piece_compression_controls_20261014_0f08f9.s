.setcpu "65816"
.segment "CODE"
.org $08F9
map_control_0f08f9:
    .byte $D7 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
