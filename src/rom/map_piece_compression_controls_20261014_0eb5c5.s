.setcpu "65816"
.segment "CODE"
.org $B5C5
map_control_0eb5c5:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
