.setcpu "65816"
.segment "CODE"
.org $2BB8
map_control_0f2bb8:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
