.setcpu "65816"
.segment "CODE"
.org $55AA
map_control_0c55aa:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
