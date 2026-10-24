.setcpu "65816"
.segment "CODE"
.org $41F5
map_control_0c41f5:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
