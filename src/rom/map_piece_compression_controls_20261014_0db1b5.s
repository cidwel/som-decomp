.setcpu "65816"
.segment "CODE"
.org $B1B5
map_control_0db1b5:
    .byte $D1 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
