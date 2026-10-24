.setcpu "65816"
.segment "CODE"
.org $9ED8
map_control_0f9ed8:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
