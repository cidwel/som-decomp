.setcpu "65816"
.segment "CODE"
.org $C72A
map_control_0ec72a:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E4 ; previous-row copy count
