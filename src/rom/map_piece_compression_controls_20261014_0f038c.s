.setcpu "65816"
.segment "CODE"
.org $038C
map_control_0f038c:
    .byte $C3 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
