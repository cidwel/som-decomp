.setcpu "65816"
.segment "CODE"
.org $33CD
map_control_0c33cd:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
