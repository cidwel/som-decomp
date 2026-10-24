.setcpu "65816"
.segment "CODE"
.org $2847
map_control_0d2847:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E4 ; previous-row copy count
