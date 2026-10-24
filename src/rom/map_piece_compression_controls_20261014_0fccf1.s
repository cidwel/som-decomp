.setcpu "65816"
.segment "CODE"
.org $CCF1
map_control_0fccf1:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
