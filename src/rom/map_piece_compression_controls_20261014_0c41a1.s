.setcpu "65816"
.segment "CODE"
.org $41A1
map_control_0c41a1:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
