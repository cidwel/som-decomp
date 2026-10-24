.setcpu "65816"
.segment "CODE"
.org $D711
map_control_0fd711:
    .byte $C2 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
