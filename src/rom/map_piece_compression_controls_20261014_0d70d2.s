.setcpu "65816"
.segment "CODE"
.org $70D2
map_control_0d70d2:
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D2 ; same-value copy count/distance
