.setcpu "65816"
.segment "CODE"
.org $9DEC
map_control_0f9dec:
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E7 ; previous-row copy count
