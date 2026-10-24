.setcpu "65816"
.segment "CODE"
.org $93F7
map_control_0f93f7:
    .byte $E0 ; previous-row copy escape
    .byte $56 ; row-distance/count
