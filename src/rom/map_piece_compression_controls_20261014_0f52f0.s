.setcpu "65816"
.segment "CODE"
.org $52F0
map_control_0f52f0:
    .byte $E1 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
