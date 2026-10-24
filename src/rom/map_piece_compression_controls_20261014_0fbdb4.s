.setcpu "65816"
.segment "CODE"
.org $BDB4
map_control_0fbdb4:
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
