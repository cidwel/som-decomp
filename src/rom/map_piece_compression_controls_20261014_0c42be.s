.setcpu "65816"
.segment "CODE"
.org $42BE
map_control_0c42be:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
