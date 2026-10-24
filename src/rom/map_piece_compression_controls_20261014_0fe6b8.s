.setcpu "65816"
.segment "CODE"
.org $E6B8
map_control_0fe6b8:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
