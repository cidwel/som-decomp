.setcpu "65816"
.segment "CODE"
.org $8B90
map_control_0c8b90:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
