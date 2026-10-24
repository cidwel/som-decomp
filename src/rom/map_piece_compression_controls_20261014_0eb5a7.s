.setcpu "65816"
.segment "CODE"
.org $B5A7
map_control_0eb5a7:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
