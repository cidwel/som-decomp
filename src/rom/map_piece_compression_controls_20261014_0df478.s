.setcpu "65816"
.segment "CODE"
.org $F478
map_control_0df478:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $63 ; row-distance/count
