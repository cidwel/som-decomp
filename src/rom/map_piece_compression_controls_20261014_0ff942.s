.setcpu "65816"
.segment "CODE"
.org $F942
map_control_0ff942:
    .byte $E3 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
