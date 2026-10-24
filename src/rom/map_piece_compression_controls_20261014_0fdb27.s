.setcpu "65816"
.segment "CODE"
.org $DB27
map_control_0fdb27:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
