.setcpu "65816"
.segment "CODE"
.org $7934
map_control_0d7934:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E2 ; previous-row copy count
