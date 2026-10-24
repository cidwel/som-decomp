.setcpu "65816"
.segment "CODE"
.org $6B30
map_control_0f6b30:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
