.setcpu "65816"
.segment "CODE"
.org $2465
map_control_0d2465:
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
