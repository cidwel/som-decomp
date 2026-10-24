.setcpu "65816"
.segment "CODE"
.org $B153
map_control_0fb153:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $86 ; distance low bit/count
