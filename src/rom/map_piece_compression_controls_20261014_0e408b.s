.setcpu "65816"
.segment "CODE"
.org $408B
map_control_0e408b:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
