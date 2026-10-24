.setcpu "65816"
.segment "CODE"
.org $93C8
map_control_0f93c8:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
