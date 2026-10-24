.setcpu "65816"
.segment "CODE"
.org $A186
map_control_0ea186:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
