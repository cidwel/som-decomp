.setcpu "65816"
.segment "CODE"
.org $F4A0
map_control_0cf4a0:
    .byte $CD ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
