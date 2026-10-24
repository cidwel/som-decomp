.setcpu "65816"
.segment "CODE"
.org $614B
map_control_0d614b:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
