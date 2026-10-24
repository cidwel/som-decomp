.setcpu "65816"
.segment "CODE"
.org $B841
map_control_0fb841:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
