.setcpu "65816"
.segment "CODE"
.org $3A79
map_control_0c3a79:
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
