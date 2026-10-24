.setcpu "65816"
.segment "CODE"
.org $D870
map_control_0ed870:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $9F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7D ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $3B ; distance low bit/count
