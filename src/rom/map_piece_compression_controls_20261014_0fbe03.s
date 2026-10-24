.setcpu "65816"
.segment "CODE"
.org $BE03
map_control_0fbe03:
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
