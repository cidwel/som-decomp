.setcpu "65816"
.segment "CODE"
.org $399D
map_control_0f399d:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E2 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
