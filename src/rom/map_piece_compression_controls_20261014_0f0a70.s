.setcpu "65816"
.segment "CODE"
.org $0A70
map_control_0f0a70:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $92 ; row-distance/count
