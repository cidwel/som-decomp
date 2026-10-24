.setcpu "65816"
.segment "CODE"
.org $094B
map_control_0f094b:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
