.setcpu "65816"
.segment "CODE"
.org $3243
map_control_0f3243:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
    .byte $E1 ; previous-row copy count
