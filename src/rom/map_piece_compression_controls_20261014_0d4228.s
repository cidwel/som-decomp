.setcpu "65816"
.segment "CODE"
.org $4228
map_control_0d4228:
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
