.setcpu "65816"
.segment "CODE"
.org $E326
map_control_0de326:
    .byte $EC ; backreference distance high bits
    .byte $88 ; distance low bit/count
