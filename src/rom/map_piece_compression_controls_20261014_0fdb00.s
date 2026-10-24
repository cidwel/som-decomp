.setcpu "65816"
.segment "CODE"
.org $DB00
map_control_0fdb00:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
