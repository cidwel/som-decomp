.setcpu "65816"
.segment "CODE"
.org $5F5D
map_control_0e5f5d:
    .byte $E0 ; previous-row copy escape
    .byte $3B ; row-distance/count
