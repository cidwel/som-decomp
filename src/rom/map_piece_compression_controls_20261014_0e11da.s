.setcpu "65816"
.segment "CODE"
.org $11DA
map_control_0e11da:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
