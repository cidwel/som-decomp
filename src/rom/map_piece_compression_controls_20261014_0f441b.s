.setcpu "65816"
.segment "CODE"
.org $441B
map_control_0f441b:
    .byte $E0 ; previous-row copy escape
    .byte $4F ; row-distance/count
    .byte $C6 ; same-value copy count/distance
