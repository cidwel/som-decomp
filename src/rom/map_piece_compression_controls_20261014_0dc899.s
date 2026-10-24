.setcpu "65816"
.segment "CODE"
.org $C899
map_control_0dc899:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $79 ; row-distance/count
