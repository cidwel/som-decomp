.setcpu "65816"
.segment "CODE"
.org $BD42
map_control_0ebd42:
    .byte $EF ; backreference distance high bits
    .byte $0D ; distance low bit/count
