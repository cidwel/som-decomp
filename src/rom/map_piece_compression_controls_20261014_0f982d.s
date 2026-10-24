.setcpu "65816"
.segment "CODE"
.org $982D
map_control_0f982d:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1F ; distance low bit/count
