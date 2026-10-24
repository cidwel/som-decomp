.setcpu "65816"
.segment "CODE"
.org $E200
map_control_0fe200:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $77 ; row-distance/count
