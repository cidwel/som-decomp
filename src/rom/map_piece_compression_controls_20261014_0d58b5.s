.setcpu "65816"
.segment "CODE"
.org $58B5
map_control_0d58b5:
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
    .byte $E1 ; previous-row copy count
