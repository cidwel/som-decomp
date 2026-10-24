.setcpu "65816"
.segment "CODE"
.org $8E41
map_control_0e8e41:
    .byte $E0 ; previous-row copy escape
    .byte $9E ; row-distance/count
