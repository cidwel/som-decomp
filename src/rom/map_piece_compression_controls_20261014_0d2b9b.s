.setcpu "65816"
.segment "CODE"
.org $2B9B
map_control_0d2b9b:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $37 ; row-distance/count
