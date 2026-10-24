.setcpu "65816"
.segment "CODE"
.org $5D1F
map_control_0f5d1f:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
