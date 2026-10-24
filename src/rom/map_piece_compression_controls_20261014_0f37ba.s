.setcpu "65816"
.segment "CODE"
.org $37BA
map_control_0f37ba:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
