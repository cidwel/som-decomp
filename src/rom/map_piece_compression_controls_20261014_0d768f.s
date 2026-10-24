.setcpu "65816"
.segment "CODE"
.org $768F
map_control_0d768f:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
