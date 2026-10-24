.setcpu "65816"
.segment "CODE"
.org $74C5
map_control_0f74c5:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
