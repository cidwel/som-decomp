.setcpu "65816"
.segment "CODE"
.org $093B
map_control_0f093b:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
