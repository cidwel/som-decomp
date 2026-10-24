.setcpu "65816"
.segment "CODE"
.org $7DDF
map_control_0e7ddf:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
