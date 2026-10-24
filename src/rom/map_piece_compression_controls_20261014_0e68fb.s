.setcpu "65816"
.segment "CODE"
.org $68FB
map_control_0e68fb:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
