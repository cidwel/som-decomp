.setcpu "65816"
.segment "CODE"
.org $B848
map_control_0eb848:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
