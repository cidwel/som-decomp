.setcpu "65816"
.segment "CODE"
.org $6CEF
map_control_0d6cef:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
