.setcpu "65816"
.segment "CODE"
.org $D817
map_control_0fd817:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
