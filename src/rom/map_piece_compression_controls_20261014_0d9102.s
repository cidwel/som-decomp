.setcpu "65816"
.segment "CODE"
.org $9102
map_control_0d9102:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $B2 ; row-distance/count
