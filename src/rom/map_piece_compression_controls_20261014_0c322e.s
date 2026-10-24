.setcpu "65816"
.segment "CODE"
.org $322E
map_control_0c322e:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
