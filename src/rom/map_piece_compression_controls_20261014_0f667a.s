.setcpu "65816"
.segment "CODE"
.org $667A
map_control_0f667a:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
