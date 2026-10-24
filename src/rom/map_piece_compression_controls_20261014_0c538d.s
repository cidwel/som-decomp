.setcpu "65816"
.segment "CODE"
.org $538D
map_control_0c538d:
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
