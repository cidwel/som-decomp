.setcpu "65816"
.segment "CODE"
.org $0C56
map_control_0f0c56:
    .byte $EE ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
