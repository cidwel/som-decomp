.setcpu "65816"
.segment "CODE"
.org $852F
map_control_0e852f:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
