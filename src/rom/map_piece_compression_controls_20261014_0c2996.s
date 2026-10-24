.setcpu "65816"
.segment "CODE"
.org $2996
map_control_0c2996:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
