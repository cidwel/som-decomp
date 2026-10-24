.setcpu "65816"
.segment "CODE"
.org $34B7
map_control_0e34b7:
    .byte $EA ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
