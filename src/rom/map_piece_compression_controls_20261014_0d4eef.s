.setcpu "65816"
.segment "CODE"
.org $4EEF
map_control_0d4eef:
    .byte $E8 ; backreference distance high bits
    .byte $AD ; distance low bit/count
