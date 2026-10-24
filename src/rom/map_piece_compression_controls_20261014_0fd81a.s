.setcpu "65816"
.segment "CODE"
.org $D81A
map_control_0fd81a:
    .byte $E1 ; previous-row copy count
    .byte $D7 ; same-value copy count/distance
    .byte $C2 ; same-value copy count/distance
