.setcpu "65816"
.segment "CODE"
.org $4932
map_control_0d4932:
    .byte $E8 ; backreference distance high bits
    .byte $AB ; distance low bit/count
