.setcpu "65816"
.segment "CODE"
.org $7848
map_control_0d7848:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $47 ; row-distance/count
