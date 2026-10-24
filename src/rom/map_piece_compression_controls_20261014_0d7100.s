.setcpu "65816"
.segment "CODE"
.org $7100
map_control_0d7100:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
