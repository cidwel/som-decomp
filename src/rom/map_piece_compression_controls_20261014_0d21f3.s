.setcpu "65816"
.segment "CODE"
.org $21F3
map_control_0d21f3:
    .byte $E3 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
