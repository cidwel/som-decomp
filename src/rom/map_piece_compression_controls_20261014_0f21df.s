.setcpu "65816"
.segment "CODE"
.org $21DF
map_control_0f21df:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
