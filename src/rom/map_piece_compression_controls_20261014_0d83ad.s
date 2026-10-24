.setcpu "65816"
.segment "CODE"
.org $83AD
map_control_0d83ad:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
