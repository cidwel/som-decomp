.setcpu "65816"
.segment "CODE"
.org $7651
map_control_0f7651:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $44 ; row-distance/count
