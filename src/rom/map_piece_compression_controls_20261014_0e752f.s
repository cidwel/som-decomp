.setcpu "65816"
.segment "CODE"
.org $752F
map_control_0e752f:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E7 ; previous-row copy count
