.setcpu "65816"
.segment "CODE"
.org $8F24
map_control_0d8f24:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
