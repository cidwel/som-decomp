.setcpu "65816"
.segment "CODE"
.org $2AD3
map_control_0f2ad3:
    .byte $E0 ; previous-row copy escape
    .byte $B5 ; row-distance/count
