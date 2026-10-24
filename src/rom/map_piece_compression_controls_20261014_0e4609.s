.setcpu "65816"
.segment "CODE"
.org $4609
map_control_0e4609:
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E2 ; previous-row copy count
