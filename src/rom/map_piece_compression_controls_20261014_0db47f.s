.setcpu "65816"
.segment "CODE"
.org $B47F
map_control_0db47f:
    .byte $EF ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
