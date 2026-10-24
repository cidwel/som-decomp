.setcpu "65816"
.segment "CODE"
.org $529C
map_control_0f529c:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
