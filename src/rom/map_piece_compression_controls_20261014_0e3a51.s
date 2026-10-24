.setcpu "65816"
.segment "CODE"
.org $3A51
map_control_0e3a51:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
