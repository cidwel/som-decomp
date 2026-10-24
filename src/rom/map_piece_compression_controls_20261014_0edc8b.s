.setcpu "65816"
.segment "CODE"
.org $DC8B
map_control_0edc8b:
    .byte $EE ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
    .byte $CB ; same-value copy count/distance
