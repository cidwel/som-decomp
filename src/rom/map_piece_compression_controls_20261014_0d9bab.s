.setcpu "65816"
.segment "CODE"
.org $9BAB
map_control_0d9bab:
    .byte $E8 ; backreference distance high bits
    .byte $99 ; distance low bit/count
