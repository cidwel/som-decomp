.setcpu "65816"
.segment "CODE"
.org $DE52
map_control_0ede52:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
