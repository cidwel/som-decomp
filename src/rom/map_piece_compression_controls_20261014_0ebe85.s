.setcpu "65816"
.segment "CODE"
.org $BE85
map_control_0ebe85:
    .byte $E8 ; backreference distance high bits
    .byte $AD ; distance low bit/count
