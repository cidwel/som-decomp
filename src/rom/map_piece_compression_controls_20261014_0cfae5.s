.setcpu "65816"
.segment "CODE"
.org $FAE5
map_control_0cfae5:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
