.setcpu "65816"
.segment "CODE"
.org $9571
map_control_0f9571:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
    .byte $E7 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
