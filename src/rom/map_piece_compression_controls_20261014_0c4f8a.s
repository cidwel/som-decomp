.setcpu "65816"
.segment "CODE"
.org $4F8A
map_control_0c4f8a:
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count
