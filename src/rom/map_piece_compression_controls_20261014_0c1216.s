.setcpu "65816"
.segment "CODE"
.org $1216
map_control_0c1216:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
