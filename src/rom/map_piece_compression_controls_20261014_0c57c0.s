.setcpu "65816"
.segment "CODE"
.org $57C0
map_control_0c57c0:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
