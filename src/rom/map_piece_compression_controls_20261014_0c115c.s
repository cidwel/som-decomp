.setcpu "65816"
.segment "CODE"
.org $115C
map_control_0c115c:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
