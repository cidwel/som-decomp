.setcpu "65816"
.segment "CODE"
.org $920A
map_control_0e920a:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
