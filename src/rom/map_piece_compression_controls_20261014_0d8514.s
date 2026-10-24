.setcpu "65816"
.segment "CODE"
.org $8514
map_control_0d8514:
    .byte $E9 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
