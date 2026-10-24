.setcpu "65816"
.segment "CODE"
.org $3910
map_control_0f3910:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
