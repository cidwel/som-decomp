.setcpu "65816"
.segment "CODE"
.org $98CF
map_control_0f98cf:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
