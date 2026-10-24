.setcpu "65816"
.segment "CODE"
.org $FD1D
map_control_0dfd1d:
    .byte $C5 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
