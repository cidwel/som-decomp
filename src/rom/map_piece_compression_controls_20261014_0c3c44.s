.setcpu "65816"
.segment "CODE"
.org $3C44
map_control_0c3c44:
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
