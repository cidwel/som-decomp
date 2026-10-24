.setcpu "65816"
.segment "CODE"
.org $95A6
map_control_0e95a6:
    .byte $E1 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
