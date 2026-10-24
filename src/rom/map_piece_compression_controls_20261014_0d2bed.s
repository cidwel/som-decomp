.setcpu "65816"
.segment "CODE"
.org $2BED
map_control_0d2bed:
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
