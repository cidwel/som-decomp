.setcpu "65816"
.segment "CODE"
.org $D33A
map_control_0ed33a:
    .byte $EF ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
