.setcpu "65816"
.segment "CODE"
.org $1BEE
map_control_0d1bee:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $A0 ; row-distance/count
