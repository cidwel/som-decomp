.setcpu "65816"
.segment "CODE"
.org $70C0
map_control_0d70c0:
    .byte $C3 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D7 ; same-value copy count/distance
