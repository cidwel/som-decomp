.setcpu "65816"
.segment "CODE"
.org $B5C9
map_control_0db5c9:
    .byte $E8 ; backreference distance high bits
    .byte $3F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $DF ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $5F ; row-distance/count
