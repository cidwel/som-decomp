.setcpu "65816"
.segment "CODE"
.org $EC00
map_control_0eec00:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
