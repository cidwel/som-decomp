.setcpu "65816"
.segment "CODE"
.org $12D6
map_control_0c12d6:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
