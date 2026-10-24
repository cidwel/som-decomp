.setcpu "65816"
.segment "CODE"
.org $60D1
map_control_0d60d1:
    .byte $E7 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
