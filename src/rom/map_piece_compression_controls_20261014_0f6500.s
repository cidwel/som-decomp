.setcpu "65816"
.segment "CODE"
.org $6500
map_control_0f6500:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
