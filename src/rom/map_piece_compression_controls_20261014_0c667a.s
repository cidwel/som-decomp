.setcpu "65816"
.segment "CODE"
.org $667A
map_control_0c667a:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $62 ; row-distance/count
