.setcpu "65816"
.segment "CODE"
.org $6D18
map_control_0d6d18:
    .byte $EE ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
