.setcpu "65816"
.segment "CODE"
.org $B70B
map_control_0db70b:
    .byte $C6 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
