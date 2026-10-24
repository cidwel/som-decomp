.setcpu "65816"
.segment "CODE"
.org $7558
map_control_0d7558:
    .byte $E0 ; previous-row copy escape
    .byte $CC ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $50 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $59 ; row-distance/count
