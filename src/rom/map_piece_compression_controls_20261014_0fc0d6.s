.setcpu "65816"
.segment "CODE"
.org $C0D6
map_control_0fc0d6:
    .byte $C9 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
