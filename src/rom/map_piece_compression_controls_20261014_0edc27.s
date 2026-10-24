.setcpu "65816"
.segment "CODE"
.org $DC27
map_control_0edc27:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $89 ; distance low bit/count
