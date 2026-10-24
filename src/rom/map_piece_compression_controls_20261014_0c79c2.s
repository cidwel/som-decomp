.setcpu "65816"
.segment "CODE"
.org $79C2
map_control_0c79c2:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
