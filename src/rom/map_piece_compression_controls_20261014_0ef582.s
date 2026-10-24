.setcpu "65816"
.segment "CODE"
.org $F582
map_control_0ef582:
    .byte $E7 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $99 ; row-distance/count
