.setcpu "65816"
.segment "CODE"
.org $C359
map_control_0dc359:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
