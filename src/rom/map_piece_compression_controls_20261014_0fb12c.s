.setcpu "65816"
.segment "CODE"
.org $B12C
map_control_0fb12c:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $86 ; distance low bit/count
