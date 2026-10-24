.setcpu "65816"
.segment "CODE"
.org $BBF2
map_control_0ebbf2:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
