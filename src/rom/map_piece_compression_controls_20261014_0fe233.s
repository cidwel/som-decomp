.setcpu "65816"
.segment "CODE"
.org $E233
map_control_0fe233:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
