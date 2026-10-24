.setcpu "65816"
.segment "CODE"
.org $41F1
map_control_0e41f1:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
