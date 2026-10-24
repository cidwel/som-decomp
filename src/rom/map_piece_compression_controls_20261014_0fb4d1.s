.setcpu "65816"
.segment "CODE"
.org $B4D1
map_control_0fb4d1:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $4E ; row-distance/count
