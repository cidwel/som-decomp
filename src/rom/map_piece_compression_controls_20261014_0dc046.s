.setcpu "65816"
.segment "CODE"
.org $C046
map_control_0dc046:
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
