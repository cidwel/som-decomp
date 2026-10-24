.setcpu "65816"
.segment "CODE"
.org $CF15
map_control_0ecf15:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
