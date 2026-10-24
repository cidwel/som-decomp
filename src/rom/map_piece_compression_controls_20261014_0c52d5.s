.setcpu "65816"
.segment "CODE"
.org $52D5
map_control_0c52d5:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
