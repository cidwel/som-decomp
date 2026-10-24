.setcpu "65816"
.segment "CODE"
.org $8303
map_control_0d8303:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
