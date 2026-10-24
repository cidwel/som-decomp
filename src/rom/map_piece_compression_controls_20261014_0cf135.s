.setcpu "65816"
.segment "CODE"
.org $F135
map_control_0cf135:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
