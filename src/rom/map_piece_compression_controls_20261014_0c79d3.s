.setcpu "65816"
.segment "CODE"
.org $79D3
map_control_0c79d3:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
