.setcpu "65816"
.segment "CODE"
.org $72ED
map_control_0f72ed:
    .byte $EC ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E7 ; previous-row copy count
