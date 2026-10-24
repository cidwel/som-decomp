.setcpu "65816"
.segment "CODE"
.org $2437
map_control_0d2437:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
