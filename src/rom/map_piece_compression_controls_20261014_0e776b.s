.setcpu "65816"
.segment "CODE"
.org $776B
map_control_0e776b:
    .byte $E7 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
