.setcpu "65816"
.segment "CODE"
.org $15EE
map_control_0d15ee:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $94 ; row-distance/count
