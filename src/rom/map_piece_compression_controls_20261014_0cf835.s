.setcpu "65816"
.segment "CODE"
.org $F835
map_control_0cf835:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E4 ; previous-row copy count
