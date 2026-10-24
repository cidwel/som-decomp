.setcpu "65816"
.segment "CODE"
.org $4A79
map_control_0e4a79:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
