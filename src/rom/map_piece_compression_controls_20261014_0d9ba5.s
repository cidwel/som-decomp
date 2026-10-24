.setcpu "65816"
.segment "CODE"
.org $9BA5
map_control_0d9ba5:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
