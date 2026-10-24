.setcpu "65816"
.segment "CODE"
.org $DF38
map_control_0fdf38:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $5E ; row-distance/count
