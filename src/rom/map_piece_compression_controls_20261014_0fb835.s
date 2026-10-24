.setcpu "65816"
.segment "CODE"
.org $B835
map_control_0fb835:
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
