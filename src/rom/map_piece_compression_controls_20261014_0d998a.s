.setcpu "65816"
.segment "CODE"
.org $998A
map_control_0d998a:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
