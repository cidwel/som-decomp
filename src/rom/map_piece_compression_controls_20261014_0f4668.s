.setcpu "65816"
.segment "CODE"
.org $4668
map_control_0f4668:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
