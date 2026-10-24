.setcpu "65816"
.segment "CODE"
.org $D716
map_control_0ed716:
    .byte $E8 ; backreference distance high bits
    .byte $67 ; distance low bit/count
