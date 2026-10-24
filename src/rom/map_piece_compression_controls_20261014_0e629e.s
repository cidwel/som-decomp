.setcpu "65816"
.segment "CODE"
.org $629E
map_control_0e629e:
    .byte $E8 ; backreference distance high bits
    .byte $44 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $C5 ; row-distance/count
