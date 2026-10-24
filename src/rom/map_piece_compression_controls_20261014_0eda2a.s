.setcpu "65816"
.segment "CODE"
.org $DA2A
map_control_0eda2a:
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $9F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
