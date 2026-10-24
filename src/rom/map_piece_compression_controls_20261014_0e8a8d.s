.setcpu "65816"
.segment "CODE"
.org $8A8D
map_control_0e8a8d:
    .byte $EC ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
