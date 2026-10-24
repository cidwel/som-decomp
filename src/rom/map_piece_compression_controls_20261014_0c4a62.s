.setcpu "65816"
.segment "CODE"
.org $4A62
map_control_0c4a62:
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
