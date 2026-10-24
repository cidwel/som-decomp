.setcpu "65816"
.segment "CODE"
.org $7EB9
map_control_0d7eb9:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
