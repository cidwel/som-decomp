.setcpu "65816"
.segment "CODE"
.org $848C
map_control_0f848c:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
