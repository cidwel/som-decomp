.setcpu "65816"
.segment "CODE"
.org $536B
map_control_0d536b:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
