.setcpu "65816"
.segment "CODE"
.org $63D5
map_control_0c63d5:
    .byte $E0 ; previous-row copy escape
    .byte $47 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
