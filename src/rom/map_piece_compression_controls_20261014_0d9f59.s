.setcpu "65816"
.segment "CODE"
.org $9F59
map_control_0d9f59:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
