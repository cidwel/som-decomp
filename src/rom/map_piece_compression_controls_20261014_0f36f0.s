.setcpu "65816"
.segment "CODE"
.org $36F0
map_control_0f36f0:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
