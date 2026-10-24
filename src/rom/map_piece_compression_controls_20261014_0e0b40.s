.setcpu "65816"
.segment "CODE"
.org $0B40
map_control_0e0b40:
    .byte $C3 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
