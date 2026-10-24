.setcpu "65816"
.segment "CODE"
.org $385F
map_control_0e385f:
    .byte $E4 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
