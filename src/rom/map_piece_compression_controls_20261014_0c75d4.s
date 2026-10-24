.setcpu "65816"
.segment "CODE"
.org $75D4
map_control_0c75d4:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
