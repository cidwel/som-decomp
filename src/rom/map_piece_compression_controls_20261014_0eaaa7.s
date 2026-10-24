.setcpu "65816"
.segment "CODE"
.org $AAA7
map_control_0eaaa7:
    .byte $E1 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
