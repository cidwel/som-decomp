.setcpu "65816"
.segment "CODE"
.org $29F9
map_control_0e29f9:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
