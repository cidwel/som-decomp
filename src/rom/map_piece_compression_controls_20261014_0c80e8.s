.setcpu "65816"
.segment "CODE"
.org $80E8
map_control_0c80e8:
    .byte $C1 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
