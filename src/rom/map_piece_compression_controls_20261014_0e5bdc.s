.setcpu "65816"
.segment "CODE"
.org $5BDC
map_control_0e5bdc:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
