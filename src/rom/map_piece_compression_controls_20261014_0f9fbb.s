.setcpu "65816"
.segment "CODE"
.org $9FBB
map_control_0f9fbb:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
