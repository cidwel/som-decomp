.setcpu "65816"
.segment "CODE"
.org $301C
map_control_0f301c:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
