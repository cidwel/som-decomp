.setcpu "65816"
.segment "CODE"
.org $EDB7
map_control_0eedb7:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
