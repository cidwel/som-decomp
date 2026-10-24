.setcpu "65816"
.segment "CODE"
.org $8E95
map_control_0d8e95:
    .byte $D1 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
