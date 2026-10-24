.setcpu "65816"
.segment "CODE"
.org $44A4
map_control_0f44a4:
    .byte $E0 ; previous-row copy escape
    .byte $36 ; row-distance/count
