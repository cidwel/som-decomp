.setcpu "65816"
.segment "CODE"
.org $3E96
map_control_0f3e96:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
