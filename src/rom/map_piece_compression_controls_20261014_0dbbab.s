.setcpu "65816"
.segment "CODE"
.org $BBAB
map_control_0dbbab:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
