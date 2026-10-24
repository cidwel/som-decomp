.setcpu "65816"
.segment "CODE"
.org $5B9E
map_control_0f5b9e:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
