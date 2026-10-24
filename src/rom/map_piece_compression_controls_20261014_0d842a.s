.setcpu "65816"
.segment "CODE"
.org $842A
map_control_0d842a:
    .byte $E0 ; previous-row copy escape
    .byte $41 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
