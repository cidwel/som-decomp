.setcpu "65816"
.segment "CODE"
.org $ADE1
map_control_0fade1:
    .byte $E0 ; previous-row copy escape
    .byte $AC ; row-distance/count
