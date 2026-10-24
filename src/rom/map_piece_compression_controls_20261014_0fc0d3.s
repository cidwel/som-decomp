.setcpu "65816"
.segment "CODE"
.org $C0D3
map_control_0fc0d3:
    .byte $D7 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
