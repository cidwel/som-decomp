.setcpu "65816"
.segment "CODE"
.org $62CE
map_control_0d62ce:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $5E ; row-distance/count
