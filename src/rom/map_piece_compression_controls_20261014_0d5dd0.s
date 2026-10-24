.setcpu "65816"
.segment "CODE"
.org $5DD0
map_control_0d5dd0:
    .byte $E8 ; backreference distance high bits
    .byte $24 ; distance low bit/count
