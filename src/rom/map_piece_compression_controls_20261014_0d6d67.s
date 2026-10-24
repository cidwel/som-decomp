.setcpu "65816"
.segment "CODE"
.org $6D67
map_control_0d6d67:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
