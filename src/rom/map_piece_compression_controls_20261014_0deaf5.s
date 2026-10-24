.setcpu "65816"
.segment "CODE"
.org $EAF5
map_control_0deaf5:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
