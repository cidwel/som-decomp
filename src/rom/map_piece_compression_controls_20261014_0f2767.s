.setcpu "65816"
.segment "CODE"
.org $2767
map_control_0f2767:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $75 ; row-distance/count
