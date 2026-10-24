.setcpu "65816"
.segment "CODE"
.org $8344
map_control_0f8344:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
