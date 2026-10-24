.setcpu "65816"
.segment "CODE"
.org $3CBF
map_control_0f3cbf:
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
