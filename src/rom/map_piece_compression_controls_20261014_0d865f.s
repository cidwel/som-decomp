.setcpu "65816"
.segment "CODE"
.org $865F
map_control_0d865f:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
