.setcpu "65816"
.segment "CODE"
.org $8ABD
map_control_0f8abd:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
