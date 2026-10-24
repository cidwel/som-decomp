.setcpu "65816"
.segment "CODE"
.org $D0E6
map_control_0fd0e6:
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
