.setcpu "65816"
.segment "CODE"
.org $58B9
map_control_0d58b9:
    .byte $E6 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $96 ; row-distance/count
