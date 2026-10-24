.setcpu "65816"
.segment "CODE"
.org $F43D
map_control_0df43d:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
