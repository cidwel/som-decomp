.setcpu "65816"
.segment "CODE"
.org $66AD
map_control_0d66ad:
    .byte $E0 ; previous-row copy escape
    .byte $BD ; row-distance/count
