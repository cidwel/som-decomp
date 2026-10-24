.setcpu "65816"
.segment "CODE"
.org $8E8A
map_control_0e8e8a:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count
