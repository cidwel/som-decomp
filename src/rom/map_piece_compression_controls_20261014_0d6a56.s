.setcpu "65816"
.segment "CODE"
.org $6A56
map_control_0d6a56:
    .byte $C3 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D7 ; same-value copy count/distance
