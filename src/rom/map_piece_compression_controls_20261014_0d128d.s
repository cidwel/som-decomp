.setcpu "65816"
.segment "CODE"
.org $128D
map_control_0d128d:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
