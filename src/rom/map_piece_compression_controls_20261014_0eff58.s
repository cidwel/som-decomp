.setcpu "65816"
.segment "CODE"
.org $FF58
map_control_0eff58:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
