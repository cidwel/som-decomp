.setcpu "65816"
.segment "CODE"
.org $C04B
map_control_0fc04b:
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
