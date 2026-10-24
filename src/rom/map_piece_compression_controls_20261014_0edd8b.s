.setcpu "65816"
.segment "CODE"
.org $DD8B
map_control_0edd8b:
    .byte $ED ; backreference distance high bits
    .byte $95 ; distance low bit/count
