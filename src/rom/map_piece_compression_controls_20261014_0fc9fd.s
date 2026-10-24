.setcpu "65816"
.segment "CODE"
.org $C9FD
map_control_0fc9fd:
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
