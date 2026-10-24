.setcpu "65816"
.segment "CODE"
.org $8285
map_control_0d8285:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
