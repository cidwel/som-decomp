.setcpu "65816"
.segment "CODE"
.org $BEC6
map_control_0fbec6:
    .byte $EC ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E6 ; previous-row copy count
