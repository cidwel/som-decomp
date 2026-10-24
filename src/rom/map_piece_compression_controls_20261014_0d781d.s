.setcpu "65816"
.segment "CODE"
.org $781D
map_control_0d781d:
    .byte $E0 ; previous-row copy escape
    .byte $45 ; row-distance/count
