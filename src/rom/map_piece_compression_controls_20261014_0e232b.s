.setcpu "65816"
.segment "CODE"
.org $232B
map_control_0e232b:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
