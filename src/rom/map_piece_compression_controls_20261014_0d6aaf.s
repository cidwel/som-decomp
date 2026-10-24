.setcpu "65816"
.segment "CODE"
.org $6AAF
map_control_0d6aaf:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E2 ; previous-row copy count
