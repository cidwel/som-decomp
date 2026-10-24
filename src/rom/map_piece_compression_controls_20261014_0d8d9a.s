.setcpu "65816"
.segment "CODE"
.org $8D9A
map_control_0d8d9a:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $B7 ; row-distance/count
