.setcpu "65816"
.segment "CODE"
.org $B98F
map_control_0db98f:
    .byte $E5 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
