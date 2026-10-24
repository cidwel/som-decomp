.setcpu "65816"
.segment "CODE"
.org $520B
map_control_0c520b:
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
