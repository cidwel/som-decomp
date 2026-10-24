.setcpu "65816"
.segment "CODE"
.org $4224
map_control_0d4224:
    .byte $E2 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
