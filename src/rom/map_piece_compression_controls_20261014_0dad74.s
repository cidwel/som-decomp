.setcpu "65816"
.segment "CODE"
.org $AD74
map_control_0dad74:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
