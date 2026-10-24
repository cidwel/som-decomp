.setcpu "65816"
.segment "CODE"
.org $8B80
map_control_0e8b80:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
