.setcpu "65816"
.segment "CODE"
.org $68B6
map_control_0d68b6:
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D7 ; same-value copy count/distance
