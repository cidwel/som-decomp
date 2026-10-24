.setcpu "65816"
.segment "CODE"
.org $F6AC
map_control_0ef6ac:
    .byte $E7 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
