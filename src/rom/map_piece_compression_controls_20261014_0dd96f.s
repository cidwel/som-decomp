.setcpu "65816"
.segment "CODE"
.org $D96F
map_control_0dd96f:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
