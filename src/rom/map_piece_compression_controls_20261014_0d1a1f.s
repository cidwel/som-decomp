.setcpu "65816"
.segment "CODE"
.org $1A1F
map_control_0d1a1f:
    .byte $C2 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
