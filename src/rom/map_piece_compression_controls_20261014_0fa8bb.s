.setcpu "65816"
.segment "CODE"
.org $A8BB
map_control_0fa8bb:
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $AE ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
