.setcpu "65816"
.segment "CODE"
.org $93A6
map_control_0f93a6:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
