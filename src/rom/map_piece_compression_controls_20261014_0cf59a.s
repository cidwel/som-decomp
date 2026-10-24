.setcpu "65816"
.segment "CODE"
.org $F59A
map_control_0cf59a:
    .byte $C4 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
