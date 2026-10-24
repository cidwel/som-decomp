.setcpu "65816"
.segment "CODE"
.org $D214
map_control_0fd214:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
