.setcpu "65816"
.segment "CODE"
.org $93E5
map_control_0f93e5:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
