.setcpu "65816"
.segment "CODE"
.org $8898
map_control_0c8898:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
