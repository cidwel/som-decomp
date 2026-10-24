.setcpu "65816"
.segment "CODE"
.org $FF43
map_control_0eff43:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
