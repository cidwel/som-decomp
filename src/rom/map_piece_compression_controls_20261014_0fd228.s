.setcpu "65816"
.segment "CODE"
.org $D228
map_control_0fd228:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E1 ; previous-row copy count
