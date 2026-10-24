.setcpu "65816"
.segment "CODE"
.org $B8BD
map_control_0eb8bd:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
