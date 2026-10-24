.setcpu "65816"
.segment "CODE"
.org $D816
map_control_0dd816:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
