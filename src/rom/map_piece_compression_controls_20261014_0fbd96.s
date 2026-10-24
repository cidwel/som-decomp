.setcpu "65816"
.segment "CODE"
.org $BD96
map_control_0fbd96:
    .byte $E1 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $31 ; row-distance/count
