.setcpu "65816"
.segment "CODE"
.org $AF4C
map_control_0eaf4c:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
