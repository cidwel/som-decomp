.setcpu "65816"
.segment "CODE"
.org $5716
map_control_0c5716:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E2 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
