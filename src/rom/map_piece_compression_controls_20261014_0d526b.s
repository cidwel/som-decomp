.setcpu "65816"
.segment "CODE"
.org $526B
map_control_0d526b:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
