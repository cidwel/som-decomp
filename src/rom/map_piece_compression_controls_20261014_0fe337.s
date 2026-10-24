.setcpu "65816"
.segment "CODE"
.org $E337
map_control_0fe337:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
