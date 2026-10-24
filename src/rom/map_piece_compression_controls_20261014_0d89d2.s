.setcpu "65816"
.segment "CODE"
.org $89D2
map_control_0d89d2:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
