.setcpu "65816"
.segment "CODE"
.org $9233
map_control_0f9233:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E3 ; previous-row copy count
