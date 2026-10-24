.setcpu "65816"
.segment "CODE"
.org $BA39
map_control_0fba39:
    .byte $E0 ; previous-row copy escape
    .byte $62 ; row-distance/count
