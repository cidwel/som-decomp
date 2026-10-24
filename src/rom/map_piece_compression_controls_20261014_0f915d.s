.setcpu "65816"
.segment "CODE"
.org $915D
map_control_0f915d:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
