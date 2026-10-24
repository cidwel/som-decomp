.setcpu "65816"
.segment "CODE"
.org $FC4D
map_control_0ffc4d:
    .byte $E1 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
