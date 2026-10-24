.setcpu "65816"
.segment "CODE"
.org $D5C6
map_control_0fd5c6:
    .byte $D1 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
