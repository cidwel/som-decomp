.setcpu "65816"
.segment "CODE"
.org $981B
map_control_0e981b:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
