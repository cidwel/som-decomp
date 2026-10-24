.setcpu "65816"
.segment "CODE"
.org $63FF
map_control_0c63ff:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
