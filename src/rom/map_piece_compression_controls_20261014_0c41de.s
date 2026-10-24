.setcpu "65816"
.segment "CODE"
.org $41DE
map_control_0c41de:
    .byte $EE ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
    .byte $E4 ; previous-row copy count
