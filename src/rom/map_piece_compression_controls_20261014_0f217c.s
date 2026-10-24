.setcpu "65816"
.segment "CODE"
.org $217C
map_control_0f217c:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
