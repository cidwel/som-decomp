.setcpu "65816"
.segment "CODE"
.org $4F3C
map_control_0c4f3c:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
