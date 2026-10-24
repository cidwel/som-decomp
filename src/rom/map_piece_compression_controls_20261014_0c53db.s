.setcpu "65816"
.segment "CODE"
.org $53DB
map_control_0c53db:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
