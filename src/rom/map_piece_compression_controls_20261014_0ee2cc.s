.setcpu "65816"
.segment "CODE"
.org $E2CC
map_control_0ee2cc:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
