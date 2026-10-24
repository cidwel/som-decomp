.setcpu "65816"
.segment "CODE"
.org $33CD
map_control_0e33cd:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
