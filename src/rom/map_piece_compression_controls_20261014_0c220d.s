.setcpu "65816"
.segment "CODE"
.org $220D
map_control_0c220d:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
