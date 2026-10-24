.setcpu "65816"
.segment "CODE"
.org $95EE
map_control_0d95ee:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
