.setcpu "65816"
.segment "CODE"
.org $7393
map_control_0c7393:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
