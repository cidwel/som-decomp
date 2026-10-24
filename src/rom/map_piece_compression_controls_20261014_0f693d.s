.setcpu "65816"
.segment "CODE"
.org $693D
map_control_0f693d:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
