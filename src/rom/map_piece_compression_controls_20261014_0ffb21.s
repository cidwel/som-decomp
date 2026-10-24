.setcpu "65816"
.segment "CODE"
.org $FB21
map_control_0ffb21:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
