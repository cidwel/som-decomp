.setcpu "65816"
.segment "CODE"
.org $754C
map_control_0e754c:
    .byte $E7 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
