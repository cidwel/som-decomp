.setcpu "65816"
.segment "CODE"
.org $C1DF
map_control_0dc1df:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
