.setcpu "65816"
.segment "CODE"
.org $3465
map_control_0f3465:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
