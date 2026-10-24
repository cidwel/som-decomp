.setcpu "65816"
.segment "CODE"
.org $4DDF
map_control_0d4ddf:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
