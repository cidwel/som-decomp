.setcpu "65816"
.segment "CODE"
.org $D6E3
map_control_0fd6e3:
    .byte $C2 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
    .byte $D1 ; same-value copy count/distance
