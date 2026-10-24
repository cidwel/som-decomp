.setcpu "65816"
.segment "CODE"
.org $3FD8
map_control_0f3fd8:
    .byte $EA ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $57 ; row-distance/count
