.setcpu "65816"
.segment "CODE"
.org $F120
map_control_0ef120:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
