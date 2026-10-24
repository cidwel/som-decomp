.setcpu "65816"
.segment "CODE"
.org $1037
map_control_0d1037:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
