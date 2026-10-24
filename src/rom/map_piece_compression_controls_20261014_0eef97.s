.setcpu "65816"
.segment "CODE"
.org $EF97
map_control_0eef97:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
