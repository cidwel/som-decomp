.setcpu "65816"
.segment "CODE"
.org $FBF7
map_control_0efbf7:
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
