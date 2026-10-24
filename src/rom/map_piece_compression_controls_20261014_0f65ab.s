.setcpu "65816"
.segment "CODE"
.org $65AB
map_control_0f65ab:
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
