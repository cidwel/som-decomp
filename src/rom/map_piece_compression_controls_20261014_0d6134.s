.setcpu "65816"
.segment "CODE"
.org $6134
map_control_0d6134:
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
