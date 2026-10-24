.setcpu "65816"
.segment "CODE"
.org $D3C0
map_control_0fd3c0:
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
