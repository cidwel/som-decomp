.setcpu "65816"
.segment "CODE"
.org $C89F
map_control_0fc89f:
    .byte $D2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
