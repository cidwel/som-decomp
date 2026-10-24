.setcpu "65816"
.segment "CODE"
.org $EAEA
map_control_0deaea:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
