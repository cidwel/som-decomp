.setcpu "65816"
.segment "CODE"
.org $F0E4
map_control_0df0e4:
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
    .byte $E1 ; previous-row copy count
