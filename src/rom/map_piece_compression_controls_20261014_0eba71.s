.setcpu "65816"
.segment "CODE"
.org $BA71
map_control_0eba71:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
