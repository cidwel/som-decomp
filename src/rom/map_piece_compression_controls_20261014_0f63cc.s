.setcpu "65816"
.segment "CODE"
.org $63CC
map_control_0f63cc:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
