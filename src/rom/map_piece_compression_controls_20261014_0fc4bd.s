.setcpu "65816"
.segment "CODE"
.org $C4BD
map_control_0fc4bd:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
