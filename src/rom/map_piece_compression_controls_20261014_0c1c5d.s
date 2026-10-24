.setcpu "65816"
.segment "CODE"
.org $1C5D
map_control_0c1c5d:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
