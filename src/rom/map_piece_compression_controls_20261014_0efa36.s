.setcpu "65816"
.segment "CODE"
.org $FA36
map_control_0efa36:
    .byte $E0 ; previous-row copy escape
    .byte $B2 ; row-distance/count
