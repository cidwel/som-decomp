.setcpu "65816"
.segment "CODE"
.org $2A2E
map_control_0e2a2e:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
