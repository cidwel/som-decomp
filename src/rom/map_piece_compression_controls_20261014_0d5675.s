.setcpu "65816"
.segment "CODE"
.org $5675
map_control_0d5675:
    .byte $C6 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D7 ; same-value copy count/distance
