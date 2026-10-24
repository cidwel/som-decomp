.setcpu "65816"
.segment "CODE"
.org $5233
map_control_0c5233:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
