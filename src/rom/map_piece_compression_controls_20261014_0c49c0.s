.setcpu "65816"
.segment "CODE"
.org $49C0
map_control_0c49c0:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
