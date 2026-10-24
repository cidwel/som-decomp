.setcpu "65816"
.segment "CODE"
.org $CD35
map_control_0ecd35:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $97 ; row-distance/count
