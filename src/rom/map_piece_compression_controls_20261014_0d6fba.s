.setcpu "65816"
.segment "CODE"
.org $6FBA
map_control_0d6fba:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
