.setcpu "65816"
.segment "CODE"
.org $74C8
map_control_0f74c8:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
