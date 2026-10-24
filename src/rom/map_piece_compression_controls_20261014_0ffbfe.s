.setcpu "65816"
.segment "CODE"
.org $FBFE
map_control_0ffbfe:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E6 ; previous-row copy count
