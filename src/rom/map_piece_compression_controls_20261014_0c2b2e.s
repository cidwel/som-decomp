.setcpu "65816"
.segment "CODE"
.org $2B2E
map_control_0c2b2e:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
