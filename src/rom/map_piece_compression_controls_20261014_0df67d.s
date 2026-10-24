.setcpu "65816"
.segment "CODE"
.org $F67D
map_control_0df67d:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $63 ; row-distance/count
