.setcpu "65816"
.segment "CODE"
.org $6FA0
map_control_0f6fa0:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
