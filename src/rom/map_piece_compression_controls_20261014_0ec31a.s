.setcpu "65816"
.segment "CODE"
.org $C31A
map_control_0ec31a:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
    .byte $E1 ; previous-row copy count
