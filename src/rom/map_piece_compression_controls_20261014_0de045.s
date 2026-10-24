.setcpu "65816"
.segment "CODE"
.org $E045
map_control_0de045:
    .byte $E0 ; previous-row copy escape
    .byte $B9 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $92 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $FF ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $DC ; row-distance/count
