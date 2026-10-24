.setcpu "65816"
.segment "CODE"
.org $8BF2
map_control_0e8bf2:
    .byte $E0 ; previous-row copy escape
    .byte $AD ; row-distance/count
