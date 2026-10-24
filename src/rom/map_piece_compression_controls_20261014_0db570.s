.setcpu "65816"
.segment "CODE"
.org $B570
map_control_0db570:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $3A ; row-distance/count
