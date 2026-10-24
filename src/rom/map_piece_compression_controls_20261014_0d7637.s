.setcpu "65816"
.segment "CODE"
.org $7637
map_control_0d7637:
    .byte $ED ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $B5 ; row-distance/count
