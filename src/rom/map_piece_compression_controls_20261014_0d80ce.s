.setcpu "65816"
.segment "CODE"
.org $80CE
map_control_0d80ce:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
