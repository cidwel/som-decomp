.setcpu "65816"
.segment "CODE"
.org $9914
map_control_0f9914:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
