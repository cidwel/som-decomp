.setcpu "65816"
.segment "CODE"
.org $57FB
map_control_0f57fb:
    .byte $EB ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
