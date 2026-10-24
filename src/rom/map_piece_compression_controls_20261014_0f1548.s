.setcpu "65816"
.segment "CODE"
.org $1548
map_control_0f1548:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
