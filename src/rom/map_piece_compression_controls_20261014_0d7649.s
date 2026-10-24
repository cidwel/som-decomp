.setcpu "65816"
.segment "CODE"
.org $7649
map_control_0d7649:
    .byte $E0 ; previous-row copy escape
    .byte $4B ; row-distance/count
