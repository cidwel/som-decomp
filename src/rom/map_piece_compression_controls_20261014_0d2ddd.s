.setcpu "65816"
.segment "CODE"
.org $2DDD
map_control_0d2ddd:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
