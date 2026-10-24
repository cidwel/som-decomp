.setcpu "65816"
.segment "CODE"
.org $0C3F
map_control_0e0c3f:
    .byte $C2 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
