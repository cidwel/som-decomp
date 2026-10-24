.setcpu "65816"
.segment "CODE"
.org $B381
map_control_0eb381:
    .byte $EC ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
