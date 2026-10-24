.setcpu "65816"
.segment "CODE"
.org $0E03
map_control_0d0e03:
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
