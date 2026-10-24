.setcpu "65816"
.segment "CODE"
.org $2A69
map_control_0d2a69:
    .byte $CB ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
