.setcpu "65816"
.segment "CODE"
.org $42B7
map_control_0e42b7:
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
