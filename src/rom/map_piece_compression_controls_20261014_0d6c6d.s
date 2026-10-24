.setcpu "65816"
.segment "CODE"
.org $6C6D
map_control_0d6c6d:
    .byte $E0 ; previous-row copy escape
    .byte $3B ; row-distance/count
