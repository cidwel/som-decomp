.setcpu "65816"
.segment "CODE"
.org $39B9
map_control_0e39b9:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
