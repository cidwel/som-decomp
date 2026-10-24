.setcpu "65816"
.segment "CODE"
.org $BE74
map_control_0ebe74:
    .byte $E0 ; previous-row copy escape
    .byte $BE ; row-distance/count
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
