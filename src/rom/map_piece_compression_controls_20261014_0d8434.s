.setcpu "65816"
.segment "CODE"
.org $8434
map_control_0d8434:
    .byte $E0 ; previous-row copy escape
    .byte $55 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $46 ; row-distance/count
