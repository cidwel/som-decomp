.setcpu "65816"
.segment "CODE"
.org $44C6
map_control_0f44c6:
    .byte $E0 ; previous-row copy escape
    .byte $36 ; row-distance/count
