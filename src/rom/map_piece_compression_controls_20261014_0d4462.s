.setcpu "65816"
.segment "CODE"
.org $4462
map_control_0d4462:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E4 ; previous-row copy count
