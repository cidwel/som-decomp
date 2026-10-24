.setcpu "65816"
.segment "CODE"
.org $F903
map_control_0ff903:
    .byte $E1 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
