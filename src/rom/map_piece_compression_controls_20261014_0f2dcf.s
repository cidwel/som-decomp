.setcpu "65816"
.segment "CODE"
.org $2DCF
map_control_0f2dcf:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
