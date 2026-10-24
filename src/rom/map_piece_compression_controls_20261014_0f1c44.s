.setcpu "65816"
.segment "CODE"
.org $1C44
map_control_0f1c44:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
