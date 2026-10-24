.setcpu "65816"
.segment "CODE"
.org $957F
map_control_0d957f:
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
