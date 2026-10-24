.setcpu "65816"
.segment "CODE"
.org $5B4B
map_control_0d5b4b:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
