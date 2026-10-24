.setcpu "65816"
.segment "CODE"
.org $2B7C
map_control_0d2b7c:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $94 ; row-distance/count
