.setcpu "65816"
.segment "CODE"
.org $22F8
map_control_0d22f8:
    .byte $E3 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
