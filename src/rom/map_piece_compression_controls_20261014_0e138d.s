.setcpu "65816"
.segment "CODE"
.org $138D
map_control_0e138d:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
