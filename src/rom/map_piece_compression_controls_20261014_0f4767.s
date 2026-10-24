.setcpu "65816"
.segment "CODE"
.org $4767
map_control_0f4767:
    .byte $E0 ; previous-row copy escape
    .byte $36 ; row-distance/count
