.setcpu "65816"
.segment "CODE"
.org $BA41
map_control_0fba41:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $53 ; row-distance/count
