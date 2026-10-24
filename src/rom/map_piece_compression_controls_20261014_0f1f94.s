.setcpu "65816"
.segment "CODE"
.org $1F94
map_control_0f1f94:
    .byte $E3 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
