.setcpu "65816"
.segment "CODE"
.org $EAD8
map_control_0dead8:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E3 ; previous-row copy count
