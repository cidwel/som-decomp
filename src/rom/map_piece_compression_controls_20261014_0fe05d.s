.setcpu "65816"
.segment "CODE"
.org $E05D
map_control_0fe05d:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
