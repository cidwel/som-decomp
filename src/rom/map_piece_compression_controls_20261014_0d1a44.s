.setcpu "65816"
.segment "CODE"
.org $1A44
map_control_0d1a44:
    .byte $C3 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
