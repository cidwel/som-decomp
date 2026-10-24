.setcpu "65816"
.segment "CODE"
.org $77DB
map_control_0c77db:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
