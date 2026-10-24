.setcpu "65816"
.segment "CODE"
.org $45B7
map_control_0e45b7:
    .byte $E4 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
