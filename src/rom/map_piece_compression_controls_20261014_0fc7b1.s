.setcpu "65816"
.segment "CODE"
.org $C7B1
map_control_0fc7b1:
    .byte $C3 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
