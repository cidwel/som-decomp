.setcpu "65816"
.segment "CODE"
.org $CCB6
map_control_0fccb6:
    .byte $EA ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
