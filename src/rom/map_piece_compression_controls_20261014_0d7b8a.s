.setcpu "65816"
.segment "CODE"
.org $7B8A
map_control_0d7b8a:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
