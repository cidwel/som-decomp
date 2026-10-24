.setcpu "65816"
.segment "CODE"
.org $1FFB
map_control_0c1ffb:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7D ; row-distance/count
