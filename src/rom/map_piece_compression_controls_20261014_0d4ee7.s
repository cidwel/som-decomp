.setcpu "65816"
.segment "CODE"
.org $4EE7
map_control_0d4ee7:
    .byte $E8 ; backreference distance high bits
    .byte $AD ; distance low bit/count
