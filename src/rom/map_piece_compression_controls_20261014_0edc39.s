.setcpu "65816"
.segment "CODE"
.org $DC39
map_control_0edc39:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
