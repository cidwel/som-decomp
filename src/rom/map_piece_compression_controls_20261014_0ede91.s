.setcpu "65816"
.segment "CODE"
.org $DE91
map_control_0ede91:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
