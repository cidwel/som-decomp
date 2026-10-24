.setcpu "65816"
.segment "CODE"
.org $200B
map_control_0d200b:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
