.setcpu "65816"
.segment "CODE"
.org $FBB2
map_control_0ffbb2:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
