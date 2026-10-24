.setcpu "65816"
.segment "CODE"
.org $D235
map_control_0fd235:
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
