.setcpu "65816"
.segment "CODE"
.org $5E7B
map_control_0c5e7b:
    .byte $CA ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $36 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
