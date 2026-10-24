.setcpu "65816"
.segment "CODE"
.org $F30A
map_control_0df30a:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
