.setcpu "65816"
.segment "CODE"
.org $890B
map_control_0e890b:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
