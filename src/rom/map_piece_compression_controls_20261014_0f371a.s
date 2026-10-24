.setcpu "65816"
.segment "CODE"
.org $371A
map_control_0f371a:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
