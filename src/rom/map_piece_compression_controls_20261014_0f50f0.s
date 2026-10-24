.setcpu "65816"
.segment "CODE"
.org $50F0
map_control_0f50f0:
    .byte $C7 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
