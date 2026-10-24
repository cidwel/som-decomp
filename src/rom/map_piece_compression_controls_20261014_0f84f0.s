.setcpu "65816"
.segment "CODE"
.org $84F0
map_control_0f84f0:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
