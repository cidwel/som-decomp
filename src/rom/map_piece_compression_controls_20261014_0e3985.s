.setcpu "65816"
.segment "CODE"
.org $3985
map_control_0e3985:
    .byte $E1 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
