.setcpu "65816"
.segment "CODE"
.org $4223
map_control_0e4223:
    .byte $E4 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
