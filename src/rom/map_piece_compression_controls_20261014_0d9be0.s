.setcpu "65816"
.segment "CODE"
.org $9BE0
map_control_0d9be0:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
