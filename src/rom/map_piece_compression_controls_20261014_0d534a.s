.setcpu "65816"
.segment "CODE"
.org $534A
map_control_0d534a:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
