.setcpu "65816"
.segment "CODE"
.org $BE91
map_control_0ebe91:
    .byte $E8 ; backreference distance high bits
    .byte $AD ; distance low bit/count
