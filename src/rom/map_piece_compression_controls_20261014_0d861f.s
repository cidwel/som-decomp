.setcpu "65816"
.segment "CODE"
.org $861F
map_control_0d861f:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
