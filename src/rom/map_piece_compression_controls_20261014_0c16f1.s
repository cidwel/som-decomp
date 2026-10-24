.setcpu "65816"
.segment "CODE"
.org $16F1
map_control_0c16f1:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
