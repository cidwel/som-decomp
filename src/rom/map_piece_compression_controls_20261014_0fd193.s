.setcpu "65816"
.segment "CODE"
.org $D193
map_control_0fd193:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
