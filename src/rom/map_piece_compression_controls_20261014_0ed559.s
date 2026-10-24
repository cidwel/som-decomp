.setcpu "65816"
.segment "CODE"
.org $D559
map_control_0ed559:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
