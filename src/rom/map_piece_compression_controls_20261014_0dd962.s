.setcpu "65816"
.segment "CODE"
.org $D962
map_control_0dd962:
    .byte $EE ; backreference distance high bits
    .byte $89 ; distance low bit/count
