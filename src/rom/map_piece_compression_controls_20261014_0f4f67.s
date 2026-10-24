.setcpu "65816"
.segment "CODE"
.org $4F67
map_control_0f4f67:
    .byte $EC ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E5 ; previous-row copy count
