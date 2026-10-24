.setcpu "65816"
.segment "CODE"
.org $F162
map_control_0df162:
    .byte $F1 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $23 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $FF ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $FF ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $FF ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $DF ; row-distance/count
