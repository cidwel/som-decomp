.setcpu "65816"
.segment "CODE"
.org $3B6C
map_control_0f3b6c:
    .byte $E0 ; previous-row copy escape
    .byte $36 ; row-distance/count
