.setcpu "65816"
.segment "CODE"
.org $27E0
map_control_0d27e0:
    .byte $E6 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
