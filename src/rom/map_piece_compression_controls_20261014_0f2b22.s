.setcpu "65816"
.segment "CODE"
.org $2B22
map_control_0f2b22:
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
