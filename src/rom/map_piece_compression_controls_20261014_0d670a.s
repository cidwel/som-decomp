.setcpu "65816"
.segment "CODE"
.org $670A
map_control_0d670a:
    .byte $C2 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
