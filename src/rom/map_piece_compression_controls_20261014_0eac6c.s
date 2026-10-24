.setcpu "65816"
.segment "CODE"
.org $AC6C
map_control_0eac6c:
    .byte $ED ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $05 ; distance low bit/count
