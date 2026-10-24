.setcpu "65816"
.segment "CODE"
.org $6BEE
map_control_0e6bee:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
