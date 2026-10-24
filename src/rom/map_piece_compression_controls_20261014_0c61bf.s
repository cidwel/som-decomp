.setcpu "65816"
.segment "CODE"
.org $61BF
map_control_0c61bf:
    .byte $E0 ; previous-row copy escape
    .byte $36 ; row-distance/count
