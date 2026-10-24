.setcpu "65816"
.segment "CODE"
.org $EE66
map_control_0dee66:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $4A ; row-distance/count
