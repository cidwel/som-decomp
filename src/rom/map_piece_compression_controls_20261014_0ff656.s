.setcpu "65816"
.segment "CODE"
.org $F656
map_control_0ff656:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
