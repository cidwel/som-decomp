.setcpu "65816"
.segment "CODE"
.org $D85D
map_control_0ed85d:
    .byte $E0 ; previous-row copy escape
    .byte $BC ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
