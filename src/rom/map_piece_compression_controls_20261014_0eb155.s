.setcpu "65816"
.segment "CODE"
.org $B155
map_control_0eb155:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $57 ; row-distance/count
