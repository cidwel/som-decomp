.setcpu "65816"
.segment "CODE"
.org $3CE1
map_control_0f3ce1:
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
