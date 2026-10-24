.setcpu "65816"
.segment "CODE"
.org $6FBE
map_control_0c6fbe:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
