.setcpu "65816"
.segment "CODE"
.org $60E7
map_control_0f60e7:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
