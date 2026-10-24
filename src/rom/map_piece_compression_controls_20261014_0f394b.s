.setcpu "65816"
.segment "CODE"
.org $394B
map_control_0f394b:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
