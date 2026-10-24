.setcpu "65816"
.segment "CODE"
.org $E8BF
map_control_0de8bf:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
