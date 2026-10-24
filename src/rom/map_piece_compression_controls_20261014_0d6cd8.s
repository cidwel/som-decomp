.setcpu "65816"
.segment "CODE"
.org $6CD8
map_control_0d6cd8:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
