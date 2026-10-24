.setcpu "65816"
.segment "CODE"
.org $6019
map_control_0d6019:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
