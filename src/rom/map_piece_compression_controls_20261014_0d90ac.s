.setcpu "65816"
.segment "CODE"
.org $90AC
map_control_0d90ac:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $29 ; distance low bit/count
