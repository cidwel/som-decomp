.setcpu "65816"
.segment "CODE"
.org $D688
map_control_0dd688:
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
