.setcpu "65816"
.segment "CODE"
.org $DD00
map_control_0ddd00:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
