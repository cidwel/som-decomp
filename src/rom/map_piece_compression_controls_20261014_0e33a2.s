.setcpu "65816"
.segment "CODE"
.org $33A2
map_control_0e33a2:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
