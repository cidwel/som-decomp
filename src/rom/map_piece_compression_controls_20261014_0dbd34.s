.setcpu "65816"
.segment "CODE"
.org $BD34
map_control_0dbd34:
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
