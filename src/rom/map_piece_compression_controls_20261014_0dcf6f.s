.setcpu "65816"
.segment "CODE"
.org $CF6F
map_control_0dcf6f:
    .byte $E6 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
