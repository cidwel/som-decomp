.setcpu "65816"
.segment "CODE"
.org $72DE
map_control_0c72de:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
