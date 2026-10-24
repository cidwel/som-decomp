.setcpu "65816"
.segment "CODE"
.org $72F2
map_control_0f72f2:
    .byte $E6 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E7 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
