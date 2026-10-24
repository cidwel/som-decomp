.setcpu "65816"
.segment "CODE"
.org $B04A
map_control_0fb04a:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $88 ; distance low bit/count
