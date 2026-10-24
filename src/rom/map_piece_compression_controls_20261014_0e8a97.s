.setcpu "65816"
.segment "CODE"
.org $8A97
map_control_0e8a97:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $EC ; backreference distance high bits
    .byte $09 ; distance low bit/count
