.setcpu "65816"
.segment "CODE"
.org $388A
map_control_0f388a:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
