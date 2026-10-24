.setcpu "65816"
.segment "CODE"
.org $4E41
map_control_0d4e41:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
