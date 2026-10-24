.setcpu "65816"
.segment "CODE"
.org $2A0A
map_control_0e2a0a:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
