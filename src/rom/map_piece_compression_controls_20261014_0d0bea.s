.setcpu "65816"
.segment "CODE"
.org $0BEA
map_control_0d0bea:
    .byte $E5 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
