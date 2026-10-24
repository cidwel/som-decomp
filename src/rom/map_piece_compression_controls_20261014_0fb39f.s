.setcpu "65816"
.segment "CODE"
.org $B39F
map_control_0fb39f:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count
