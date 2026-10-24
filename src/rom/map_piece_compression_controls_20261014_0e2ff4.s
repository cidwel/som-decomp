.setcpu "65816"
.segment "CODE"
.org $2FF4
map_control_0e2ff4:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
