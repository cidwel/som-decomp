.setcpu "65816"
.segment "CODE"
.org $87C4
map_control_0f87c4:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
