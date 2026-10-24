.setcpu "65816"
.segment "CODE"
.org $9BC5
map_control_0d9bc5:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
