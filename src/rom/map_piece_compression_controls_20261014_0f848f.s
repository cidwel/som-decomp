.setcpu "65816"
.segment "CODE"
.org $848F
map_control_0f848f:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
