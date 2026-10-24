.setcpu "65816"
.segment "CODE"
.org $F137
map_control_0ef137:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
