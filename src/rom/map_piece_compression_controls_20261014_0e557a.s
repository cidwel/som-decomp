.setcpu "65816"
.segment "CODE"
.org $557A
map_control_0e557a:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
