.setcpu "65816"
.segment "CODE"
.org $85FA
map_control_0f85fa:
    .byte $C2 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
