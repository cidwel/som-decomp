.setcpu "65816"
.segment "CODE"
.org $87F7
map_control_0d87f7:
    .byte $E7 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
