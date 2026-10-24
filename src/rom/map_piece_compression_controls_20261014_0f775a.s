.setcpu "65816"
.segment "CODE"
.org $775A
map_control_0f775a:
    .byte $E9 ; backreference distance high bits
    .byte $8F ; distance low bit/count
