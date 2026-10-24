.setcpu "65816"
.segment "CODE"
.org $99A7
map_control_0e99a7:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E4 ; previous-row copy count
