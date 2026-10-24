.setcpu "65816"
.segment "CODE"
.org $CBFB
map_control_0fcbfb:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $3E ; row-distance/count
