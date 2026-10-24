.setcpu "65816"
.segment "CODE"
.org $2413
map_control_0e2413:
    .byte $DF ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
