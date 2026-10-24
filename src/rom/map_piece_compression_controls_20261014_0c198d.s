.setcpu "65816"
.segment "CODE"
.org $198D
map_control_0c198d:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
