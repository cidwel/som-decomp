.setcpu "65816"
.segment "CODE"
.org $71F1
map_control_0d71f1:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $06 ; distance low bit/count
