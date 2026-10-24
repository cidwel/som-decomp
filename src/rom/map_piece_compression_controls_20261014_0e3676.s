.setcpu "65816"
.segment "CODE"
.org $3676
map_control_0e3676:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $6A ; row-distance/count
