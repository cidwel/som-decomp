.setcpu "65816"
.segment "CODE"
.org $757D
map_control_0d757d:
    .byte $E0 ; previous-row copy escape
    .byte $C8 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $43 ; row-distance/count
