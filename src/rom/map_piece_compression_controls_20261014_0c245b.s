.setcpu "65816"
.segment "CODE"
.org $245B
map_control_0c245b:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
    .byte $C6 ; same-value copy count/distance
