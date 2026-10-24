.setcpu "65816"
.segment "CODE"
.org $1FCD
map_control_0d1fcd:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
