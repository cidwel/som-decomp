.setcpu "65816"
.segment "CODE"
.org $1ACF
map_control_0d1acf:
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
