.setcpu "65816"
.segment "CODE"
.org $D11F
map_control_0dd11f:
    .byte $E1 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
