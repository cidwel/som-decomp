.setcpu "65816"
.segment "CODE"
.org $D826
map_control_0fd826:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
