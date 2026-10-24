.setcpu "65816"
.segment "CODE"
.org $DEF1
map_control_0ddef1:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
