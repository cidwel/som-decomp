.setcpu "65816"
.segment "CODE"
.org $BBF6
map_control_0dbbf6:
    .byte $EB ; backreference distance high bits
    .byte $87 ; distance low bit/count
