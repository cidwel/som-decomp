.setcpu "65816"
.segment "CODE"
.org $85DB
map_control_0c85db:
    .byte $E0 ; previous-row copy escape
    .byte $39 ; row-distance/count
    .byte $C7 ; same-value copy count/distance
