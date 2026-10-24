.setcpu "65816"
.segment "CODE"
.org $EE56
map_control_0eee56:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
