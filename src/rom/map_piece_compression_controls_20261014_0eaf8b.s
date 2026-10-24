.setcpu "65816"
.segment "CODE"
.org $AF8B
map_control_0eaf8b:
    .byte $D6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
