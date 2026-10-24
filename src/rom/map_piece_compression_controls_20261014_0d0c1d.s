.setcpu "65816"
.segment "CODE"
.org $0C1D
map_control_0d0c1d:
    .byte $C2 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
