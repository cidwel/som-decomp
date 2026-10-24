.setcpu "65816"
.segment "CODE"
.org $46DE
map_control_0f46de:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
