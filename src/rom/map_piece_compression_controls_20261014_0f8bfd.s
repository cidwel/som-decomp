.setcpu "65816"
.segment "CODE"
.org $8BFD
map_control_0f8bfd:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
