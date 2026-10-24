.setcpu "65816"
.segment "CODE"
.org $7F98
map_control_0c7f98:
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
