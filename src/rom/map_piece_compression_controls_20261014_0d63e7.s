.setcpu "65816"
.segment "CODE"
.org $63E7
map_control_0d63e7:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $49 ; row-distance/count
