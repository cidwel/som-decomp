.setcpu "65816"
.segment "CODE"
.org $689F
map_control_0f689f:
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
