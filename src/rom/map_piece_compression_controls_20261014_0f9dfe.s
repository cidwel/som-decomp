.setcpu "65816"
.segment "CODE"
.org $9DFE
map_control_0f9dfe:
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E6 ; previous-row copy count
