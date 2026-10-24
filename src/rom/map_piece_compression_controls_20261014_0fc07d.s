.setcpu "65816"
.segment "CODE"
.org $C07D
map_control_0fc07d:
    .byte $C5 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
