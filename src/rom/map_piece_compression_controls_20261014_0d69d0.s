.setcpu "65816"
.segment "CODE"
.org $69D0
map_control_0d69d0:
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count
    .byte $E2 ; previous-row copy count
