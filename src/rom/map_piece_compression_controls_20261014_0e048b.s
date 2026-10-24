.setcpu "65816"
.segment "CODE"
.org $048B
map_control_0e048b:
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
