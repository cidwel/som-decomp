.setcpu "65816"
.segment "CODE"
.org $13DA
map_control_0f13da:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
