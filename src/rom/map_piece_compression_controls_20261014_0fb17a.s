.setcpu "65816"
.segment "CODE"
.org $B17A
map_control_0fb17a:
    .byte $ED ; backreference distance high bits
    .byte $86 ; distance low bit/count
