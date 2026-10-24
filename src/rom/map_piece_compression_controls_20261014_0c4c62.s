.setcpu "65816"
.segment "CODE"
.org $4C62
map_control_0c4c62:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
