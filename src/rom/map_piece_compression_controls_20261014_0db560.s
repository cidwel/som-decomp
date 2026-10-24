.setcpu "65816"
.segment "CODE"
.org $B560
map_control_0db560:
    .byte $E1 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
