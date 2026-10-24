.setcpu "65816"
.segment "CODE"
.org $86F7
map_control_0d86f7:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
