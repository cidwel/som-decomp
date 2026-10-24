.setcpu "65816"
.segment "CODE"
.org $1ADF
map_control_0f1adf:
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
    .byte $C1 ; same-value copy count/distance
