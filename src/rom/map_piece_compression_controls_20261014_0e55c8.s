.setcpu "65816"
.segment "CODE"
.org $55C8
map_control_0e55c8:
    .byte $E4 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
