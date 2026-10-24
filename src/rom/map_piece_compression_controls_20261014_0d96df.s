.setcpu "65816"
.segment "CODE"
.org $96DF
map_control_0d96df:
    .byte $E8 ; backreference distance high bits
    .byte $98 ; distance low bit/count
