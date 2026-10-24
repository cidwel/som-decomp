.setcpu "65816"
.segment "CODE"
.org $F296
map_control_0df296:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
