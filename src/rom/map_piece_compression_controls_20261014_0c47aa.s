.setcpu "65816"
.segment "CODE"
.org $47AA
map_control_0c47aa:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
