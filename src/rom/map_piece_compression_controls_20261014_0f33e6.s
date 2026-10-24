.setcpu "65816"
.segment "CODE"
.org $33E6
map_control_0f33e6:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
