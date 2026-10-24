.setcpu "65816"
.segment "CODE"
.org $76DF
map_control_0e76df:
    .byte $E5 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
