.setcpu "65816"
.segment "CODE"
.org $47A7
map_control_0c47a7:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
