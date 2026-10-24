.setcpu "65816"
.segment "CODE"
.org $8B98
map_control_0f8b98:
    .byte $E8 ; backreference distance high bits
    .byte $9D ; distance low bit/count
