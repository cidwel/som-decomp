.setcpu "65816"
.segment "CODE"
.org $B5F9
map_control_0fb5f9:
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
