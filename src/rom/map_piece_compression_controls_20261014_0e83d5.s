.setcpu "65816"
.segment "CODE"
.org $83D5
map_control_0e83d5:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
