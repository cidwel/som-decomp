.setcpu "65816"
.segment "CODE"
.org $3B9B
map_control_0e3b9b:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
