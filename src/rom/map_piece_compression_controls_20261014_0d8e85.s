.setcpu "65816"
.segment "CODE"
.org $8E85
map_control_0d8e85:
    .byte $E0 ; previous-row copy escape
    .byte $9E ; row-distance/count
