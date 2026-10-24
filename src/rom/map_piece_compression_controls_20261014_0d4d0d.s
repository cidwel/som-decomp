.setcpu "65816"
.segment "CODE"
.org $4D0D
map_control_0d4d0d:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
