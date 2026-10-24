.setcpu "65816"
.segment "CODE"
.org $9973
map_control_0f9973:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
