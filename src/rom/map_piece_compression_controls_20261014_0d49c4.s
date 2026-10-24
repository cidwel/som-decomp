.setcpu "65816"
.segment "CODE"
.org $49C4
map_control_0d49c4:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
