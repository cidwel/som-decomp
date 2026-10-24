.setcpu "65816"
.segment "CODE"
.org $4948
map_control_0c4948:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
