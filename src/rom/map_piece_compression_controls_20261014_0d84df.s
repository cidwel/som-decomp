.setcpu "65816"
.segment "CODE"
.org $84DF
map_control_0d84df:
    .byte $C1 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $23 ; distance low bit/count
    .byte $E4 ; previous-row copy count
