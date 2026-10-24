.setcpu "65816"
.segment "CODE"
.org $FBF1
map_control_0dfbf1:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
