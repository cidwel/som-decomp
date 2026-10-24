.setcpu "65816"
.segment "CODE"
.org $1056
map_control_0d1056:
    .byte $E3 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
