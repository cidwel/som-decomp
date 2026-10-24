.setcpu "65816"
.segment "CODE"
.org $AEFD
map_control_0eaefd:
    .byte $E0 ; previous-row copy escape
    .byte $96 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $FF ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $FF ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $FF ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $FF ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $9F ; row-distance/count
