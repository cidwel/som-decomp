.setcpu "65816"
.segment "CODE"
.org $95C0
map_control_0d95c0:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
