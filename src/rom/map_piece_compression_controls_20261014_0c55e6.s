.setcpu "65816"
.segment "CODE"
.org $55E6
map_control_0c55e6:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
