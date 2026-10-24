.setcpu "65816"
.segment "CODE"
.org $681C
map_control_0f681c:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
