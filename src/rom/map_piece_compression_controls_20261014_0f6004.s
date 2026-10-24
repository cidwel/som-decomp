.setcpu "65816"
.segment "CODE"
.org $6004
map_control_0f6004:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
    .byte $C1 ; same-value copy count/distance
