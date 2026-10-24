.setcpu "65816"
.segment "CODE"
.org $1AEE
map_control_0c1aee:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
