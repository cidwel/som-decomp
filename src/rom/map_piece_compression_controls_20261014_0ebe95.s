.setcpu "65816"
.segment "CODE"
.org $BE95
map_control_0ebe95:
    .byte $E8 ; backreference distance high bits
    .byte $AD ; distance low bit/count
