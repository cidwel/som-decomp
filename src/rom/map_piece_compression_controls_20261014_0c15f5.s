.setcpu "65816"
.segment "CODE"
.org $15F5
map_control_0c15f5:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
