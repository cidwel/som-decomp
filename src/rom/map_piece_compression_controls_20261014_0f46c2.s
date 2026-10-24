.setcpu "65816"
.segment "CODE"
.org $46C2
map_control_0f46c2:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
