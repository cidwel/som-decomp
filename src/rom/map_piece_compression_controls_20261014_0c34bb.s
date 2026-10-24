.setcpu "65816"
.segment "CODE"
.org $34BB
map_control_0c34bb:
    .byte $E1 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
