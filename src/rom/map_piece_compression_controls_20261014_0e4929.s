.setcpu "65816"
.segment "CODE"
.org $4929
map_control_0e4929:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
