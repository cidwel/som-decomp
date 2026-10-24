.setcpu "65816"
.segment "CODE"
.org $4564
map_control_0f4564:
    .byte $E0 ; previous-row copy escape
    .byte $36 ; row-distance/count
