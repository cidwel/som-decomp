.setcpu "65816"
.segment "CODE"
.org $9CEB
map_control_0d9ceb:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
