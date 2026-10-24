.setcpu "65816"
.segment "CODE"
.org $C8F3
map_control_0fc8f3:
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
