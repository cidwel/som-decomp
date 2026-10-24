.setcpu "65816"
.segment "CODE"
.org $BA45
map_control_0eba45:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
