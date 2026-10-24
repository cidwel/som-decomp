.setcpu "65816"
.segment "CODE"
.org $52EF
map_control_0e52ef:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
