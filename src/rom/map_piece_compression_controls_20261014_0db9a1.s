.setcpu "65816"
.segment "CODE"
.org $B9A1
map_control_0db9a1:
    .byte $E7 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
