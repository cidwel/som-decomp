.setcpu "65816"
.segment "CODE"
.org $323B
map_control_0d323b:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
